import random as rand
import sys

print 40
for i in xrange(0,40):
    sys.stdout.write(str(rand.randrange(2147483647)) + " ")
