import sys
name = sys.argv[1]
with open(name, 'w') as ind:
    ind.write("#pragma once\n")
    ind.write("struct AAA{\n")
    ind.write("   int aaa = 3;\n")
    ind.write("};")
