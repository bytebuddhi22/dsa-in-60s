"""DSA in 60s #05: Stack, Valid Parentheses (Python version of the video's C++ code)."""

OPEN = {")": "(", "]": "[", "}": "{"}  # matching opener of each closer


def is_valid(s):
    """True if every bracket is closed by the same type, in the right order. O(n)"""
    st = []
    for c in s:
        if c in "([{":
            st.append(c)
        else:
            if not st or st[-1] != OPEN[c]:
                return False
            st.pop()
    return not st


if __name__ == "__main__":
    print(is_valid("{[()]}"))  # True
    print(is_valid("(]"))      # False
    print(is_valid("(()"))     # False
