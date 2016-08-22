#!/usr/bin/python

from subprocess import PIPE, Popen

f = open('input', 'r')

inp = []
out = []
str = ""
for line in f:
    if line == "--\n":
	inp += [str.strip()]
	str = ""
    elif line == "----\n":
	out += [str.strip()]
	str = ""
    else:
	str += line
f.close()

for i in range(len(inp)):
    p = Popen("./a.exe", stdout=PIPE, stdin=PIPE)
    res = (p.communicate(input=inp[i])[0]).decode().strip()
    if out[i] != res:
	print "output is wrong for input :", i+1
	print "expected :", out[i]
	print "found :", res
    else:
	print "Test",i+1,"passed"
