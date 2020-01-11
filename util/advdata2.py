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
def parse_room_action(line):
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
        return False
    m = re.match(".* DB\s+'([^']+)',\s*(\d+)", line)
    if m:
        print('    "{}",'.format(m.group(1)))
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

def parse_rmobdf(line):
    m = re.match(".* (\d+)\s+DUP\s*\(0\)", line)
    if m:
        num = int(m.group(1))
        print("    {},".format(", ".join([ "0" ] * num)))
        return True
    m = re.match(".* DB\s+(.*)", line)
    if m:
        olist = m.group(1).split(",")
        if re.match("RMTBEND", line):
            print("    {}".format(", ".join(olist)))
            return False
        else:
            print("    {},".format(", ".join(olist)))
            return True
    return False

def parse_pnttab(line):
    if re.match(".* EQU\s+\$", line):
        return True
    if re.match(".* DB\s+0", line):
        print("    { 0 }")
        return False
    m = re.match(".* DB\s+(\d+),\s*(\d+)", line)
    if m:
        print("    {{ {}, {} }},".format(m.group(1), m.group(2)))
        return True
    return False

def parse_scrind(line):
    if not line:
        return False
    m = re.match(".* DB\s+([\d,]+)", line)
    if m:
        olist = m.group(1).split(",")
        print("    {},".format(", ".join(olist)))
        return True
    return False

def parse_equtab(line):
    if not line:
        return False
    m = re.match(".* DB\s+([\d,]+)\s(.*)", line)
    if m:
        olist = m.group(1).split(",")
        cmt = m.group(2).replace(";", "// ")
        print("    {}, {}".format(", ".join(olist), cmt))
        return True
    return False

def parse_movobj(line):
    if not line:
        return True
    if re.match(".* EQU\s+\$", line):
        return True
    if re.match("\s*DB\s+0\s*$", line):
        print("    0")
        return False
    m = re.match(".* DB\s+([\d,]+)\s(.*)", line)
    if m:
        olist = m.group(1).split(",")
        cmt = m.group(2).replace(";", "// ")
        print("    {}, {}".format(", ".join(olist), cmt))
        return True
    m = re.match(".* DB\s+([\d,]+)", line)
    if m:
        olist = m.group(1).split(",")
        print("    {},".format(", ".join(olist)))
        return True
    return False

words = {
    "C$THE" : "the ",
    "C$SMAL": "small ",
    "C$YOU" : "you ",
    "C$ARE" : "are ",
    "C$SEE" : "see ",
    "C$CANT": "can't ",
    "C$DONT": "don't ",
    "C$LARG": "large ",
    "C$IM"  : "I'm ",
    "C$INA" : "in a ",
    "C$ONA" : "on a ",
    "C$ISA" : "is a ",
    "C$IITS": "It's ",
    "C$TTHE": "The ",
    "C$IS"  : "is ",
    "C$AND" : "and ",
    "C$AN"  : "an ",
    "C$AT"  : "at ",
    "C$OF"  : "of ",
    "C$ITSA": "it's a ",
    "C$TREK": "Trek",
    "C$TO"  : "to ",
    "C$MY"  : "my ",
    "C$IN"  : "in ",
    "C$ON"  : "on ",
}

def fix_msg(x):
    if x == "13":
        return "\\n"
    if x == "8":
        return "\\r"
    if x  == "0":
        return ""
    if x == "QUOTE+80H":
        return "' "
    if x == "QUOTE":
        return "'"
    # workaround for fake tokenization (',')
    if x == "'":
        return ""
    if x == "'+80H":
        return ", "
    m = re.match("'(.)'\+80H", x)
    if m:
        return "{} ".format(m.group(1))
    m = re.match("'(.*)'", x)
    if m:
        return m.group(1)
    if x in words.keys():
        return words[x]
    return x

msg = []
def parse_message(line):
    global msg
    if not line:
        print('"{}",'.format(''.join(msg)))
        return True
    if re.match(";", line):
        return False
    m = re.match("MSG(\d+)\s", line)
    if m:
       num = int(m.group(1))
       print("    [{}] = ".format(num), end='') 
       msg = []
    m = re.match(".* DB\s+(.*)", line)
    if m:
       parts = m.group(1).split(",")
       parts = [ fix_msg(x) for x in parts ]
       parts = [ x.replace('"', '\\"') for x in parts ]
       msg.extend(parts)
       return True
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
            print("\nstruct room_action entrtb[] = {")
            mode = "entrtb"
        elif re.match("EXITTB", line):
            print("\nstruct room_action exittb[] = {")
            mode = "exittb"
        elif re.match("INRMTB", line):
            print("\nstruct room_action inrmtb[] = {")
            mode = "inrmtb"
        elif re.match("OBJMSG", line):
            print("\nstruct object_msg objmsg[] = {")
            mode = "objmsg"
        elif re.match("THEMTB", line):
            print("\nstruct them_table themtb[] = {")
            mode = "themtb"
        elif re.match("LITTAB", line):
            print("\nchar *pronoun[] = {")
            mode = "littab"
        elif re.match("RMTBDF", line):
            print("\nstruct room_map rmtbdf[] = {")
            mode = "rmtbdf"
        elif re.match("RMOBDF", line):
            print("\nint rmobdf[] = {")
            mode = "rmobdf"
        elif re.match("ROOMTB", line):
            print("\nstruct room_map *roomtb;\n")
        elif re.match("RMOBTB1", line):
            print("\nint *rmobtb1;\n")
        elif re.match("RMOBTB2", line):
            pass
        elif re.match("RMTB_LEN", line):
            print("\nint rmtb_len = sizeof(rmtbdf);\n")
        elif re.match("PNTTAB", line):
            print("\nstruct point_table pnttab[] = {")
            mode = "pnttab"
        elif re.match("SCRIND", line):
            print("\nint scrind[] = {")
            mode = "scrind"
        elif re.match("EQUTAB", line):
            print("\nint equtab[] = {")
            mode = "equtab"
        elif re.match("ANTTAB", line):
            print("\nstruct room_action anttab[] = {")
            mode = "anttab"
        elif re.match("PUTTAB", line):
            pass
        elif re.match("MOVOBJ", line):
            print("\nint movobj[] = {")
            mode = "movobj"
        elif re.match("MSG000", line):
            print("\nchar *message[] = {")
            mode = "message"

        line = line.rstrip()

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
            if parse_room_action(line):
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
        elif mode == "rmobdf":
            if parse_rmobdf(line):
                continue
            print("};\n")
            mode = "None"
        elif mode == "pnttab":
            if parse_pnttab(line):
                continue
            print("};\n")
            mode = "None"
        elif mode == "scrind":
            if parse_scrind(line):
                continue
            print("};\n")
            mode = "None"
        elif mode == "equtab":
            if parse_equtab(line):
                continue
            print("};\n")
            mode = "None"
        elif mode == "anttab":
            if parse_room_action(line):
                continue
            print("};\n")
            mode = "None"
        elif mode == "movobj":
            if parse_movobj(line):
                continue
            print("};\n")
            mode = "None"
        elif mode == "message":
            if parse_message(line):
                continue
            print("};\n")
            mode = "None"

def main():
    print('#include <stdlib.h>')
    print('#include "advsys.h"')
    print('#include "advcode1.h"')
    print('#include "advcode2.h"')
    print()
    with open(sys.argv[1]) as fin:
        parse_all(fin)

if __name__ == "__main__":
    main()
