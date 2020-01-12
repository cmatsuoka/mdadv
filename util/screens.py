#!/usr/bin/env python3

import re
import sys

def parse_comment(line):
    print(line.rstrip().replace(";", "//"))

def fix_part(x):
    x = x.strip("H")
    x = "0x" + x
    num = int(x, 0)
    return "0x{:02x}".format(num)

def parse_all(fin):
    prev = False

    for line in fin:
        if re.match("\s*;\s*", line):
            parse_comment(line)
            continue

        # Check start of new data structure
        m = re.match("([A-Z]+)", line)
        if m:
            if prev:
                print("};")
            print("\nuint8_t {}[] = {{".format(m.group(1)).lower())
            continue

        m = re.match(".* DB\s+(.*)", line)
        if m:
            parts = m.group(1).split(",")
            parts = [ fix_part(x) for x in parts ]
            print("    {},".format(", ".join(parts)))
            prev = True

def main():
    print('#include <stdint.h>')
    print()
    with open(sys.argv[1]) as fin:
        parse_all(fin)

if __name__ == "__main__":
    main()
