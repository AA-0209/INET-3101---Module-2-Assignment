# INET-3101---Module-2-Assignment

# Problem & Audit Summary: Explain what bugs were in the starter code and how your refactored solution resolves them.
The bugs in the starter code and how I fixed them:
- No base bounds check
    - I made it so only bases 2 through 16 were valid and rejected anything outside that range
- digits above 9 printed incorrectly
    - made it so it convered remainders into hexadecimal letters a-f
- missing base prefixes
    - added 0 for octal and 0x for hexadecimal output
- poor handling of edge cases
    - handled zero, negative numbers and others safely

# Call-Stack Tracing: Pick one recursive test case (e.g., to_base_n(129, 16)). Trace the function call stack step-by-step, showing variable states (gnum, base, r) during active recursion and during unwind/printing.
- First: print_digits(129, 16) → remainder 1
- Second: print_digits(8, 16) → remainder 8
- Third: print_digits(0, 16) → remainder 0
Final Answer: 0x81

# AI Tool Reflection: Copy/paste code into ChatGPT or Claude asking it to fix the starter code. Document where the AI gave a good suggestion versus where it missed edge cases or required human oversight.
- First: It added a guard rejecting anything outside 2–16 before recursing.
- Second: It swapped printf("%d", r) for a lookup into "0123456789abcdef" so remainders 10–15 print as a–f.
- Third: It forgot to fix the prefix formatting 
- Fourth: It didn't even bother to touch prefix formatting
- Fifth: It inlined num % base into the printf instead of computing r up front
- Sixth: It removed any of the unnecessary comments 
