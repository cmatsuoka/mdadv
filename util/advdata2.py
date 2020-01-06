#!/usr/bin/env python3

import re
import sys

def parse_comment(line):
    print(line.rstrip().replace(";", "//"))

def parse_verb_noun_tb(line):
    if re.match(".* DB\s+0", line):
        print("    { NULL, 0 }")
        return False
    m = re.match(".* DB\s+'([^']+)',\s*(\d+)", line)
    if m:
        print('    {{ "{}", {} }},'.format(m.group(1), m.group(2)))
        return True
    return False

def parse_spcrtn(line):
    if re.match(".* DW\s+0$", line):
        print("    { 0x0000, NULL }")
        return False
    m = re.match(".* DW\s+([0-9A-F]+)H,\s*(\w+)(.*)", line)
    if m:
        num = int(m.group(1), 16)
        cmt = m.group(3).replace(";", "// ")
        print("    {{ 0x{:04x}, {} }}, {}".format(num, m.group(2).lower(), cmt))
        return True
    return False

room_num = 0
def parse_entr_exit_tb(line):
    global room_num
    m = re.match(".* DB\s+(\d+)\s*$", line)
    if m:
        room_num = int(m.group(1))
        if room_num == 0:
            print("    { 0, NULL }")
            return False
        return True
    m = re.match(".* DW\s+(\w+)", line)
    if m:
        print("    {{ {}, {} }},".format(room_num, m.group(1).lower()))
        return True
    return False

def parse_objmsg(line):
    if re.match(".* DB\s+0", line):
        print("    { 0 }")
        return False
    m = re.match(".* DB\s+(\d+),\s*(\d+),\s*(\d+)(.*)", line)
    if m:
        cmt = m.group(4).replace(";", "// ")
        print("    {{ {}, {}, {} }}, {}".format(m.group(1), m.group(2), m.group(3), cmt))
        return True
    return False

def parse_themtb(line):
    if re.match(".* EQU\s+\$", line):
        return True
    if re.match(".* DB\s+0", line):
        print("    { 0 }")
        return False
    m = re.match(".* DB\s+(\d+),\s*(\d+)(.*)", line)
    if m:
        cmt = m.group(3).replace(";", "// ")
        print("    {{ {}, {} }}, {}".format(m.group(1), m.group(2), cmt))
        return True
    return False

def parse_littab(line):
    if not line:
        print("    { NULL, 0 }")
        return False
    m = re.match(".* DB\s+'([^']+)',\s*(\d+)", line)
    if m:
        print('    {{ "{}", {} }},'.format(m.group(1), m.group(2)))
        return True
    return False

def parse_rmtbdf(line):
    m = re.match(".* DB\s+(\d+),\s*(\d+),\s*(\d+),\s*(\d+),\s*(\d+),\s*(\d+)", line)
    if m:
        print("    {{ {}, {}, {}, {}, {}, {} }},".format(
            m.group(1), m.group(2), m.group(3), m.group(4), m.group(5), m.group(6)
        ))
        return True
    print("    { -1 }")
    return False

def parse_all(fin):
    mode = None

    for line in fin:
        if re.match("\s*;\s*", line):
            parse_comment(line)
            continue

        # Check start of new data structure
        if re.match("VERBTB", line):
            print("\nstruct verb_noun verbtb[] = {")
            mode = "verbtb"
        elif re.match("NOUNTB", line):
            print("\nstruct verb_noun nountb[] = {")
            mode = "nountb"
        elif re.match("SPCRTN", line):
            print("\nstruct special_action spcrtn[] = {")
            mode = "spcrtn"
        elif re.match("ENTRTB", line):
            print("\nstruct entr_exit entrtb[] = {")
            mode = "entrtb"
        elif re.match("EXITTB", line):
            print("\nstruct entr_exit exittb[] = {")
            mode = "exittb"
        elif re.match("INRMTB", line):
            print("\nstruct entr_exit inrmtb[] = {")
            mode = "inrmtb"
        elif re.match("OBJMSG", line):
            print("\nstruct object_msg objmsg[] = {")
            mode = "objmsg"
        elif re.match("THEMTB", line):
            print("\nstruct them_table themtb[] = {")
            mode = "themtb"
        elif re.match("LITTAB", line):
            print("\nstruct pronoun littab[] = {")
            mode = "littab"
        elif re.match("RMTBDF", line):
            print("\nstruct room_map rmtbdf[] = {")
            mode = "rmtbdf"

        # Process current data structure
        if mode == "verbtb" or mode == "nountb":
            if parse_verb_noun_tb(line):
                continue
            print("};\n")
            mode = "None"
        elif mode == "spcrtn":
            if parse_spcrtn(line):
                continue
            print("};\n")
            mode = "None"
        elif mode == "entrtb" or mode == "exittb" or mode == "inrmtb":
            if parse_entr_exit_tb(line):
                continue
            print("};\n")
            mode = "None"
        elif mode == "objmsg":
            if parse_objmsg(line):
                continue
            print("};\n")
            mode = "None"
        elif mode == "themtb":
            if parse_themtb(line):
                continue
            print("};\n")
            mode = "None"
        elif mode == "littab":
            if parse_littab(line):
                continue
            print("};\n")
            mode = "None"
        elif mode == "rmtbdf":
            if parse_rmtbdf(line):
                continue
            print("};\n")
            mode = "None"

def main():
    print('#include <stdlib.h>"')
    print('#include "advsys.h"')
    print('#include "advcode1.h"')
    print('#include "advcode2.h"')
    print()
    with open(sys.argv[1]) as fin:
        parse_all(fin)

if __name__ == "__main__":
    main()
