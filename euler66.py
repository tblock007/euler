# DESCRIPTION: This equation is known as Pell's Equation, and is well-known for 
# its association with continued fractions.  More specifically, for a given D, 
# the integer solution (x,y) with minimum x is known as the fundamental solution, 
# and x/y is guaranteed to be in the sequence of convergents to the regular 
# continued fraction for sqrt(D)
#
# So, we simply find the sequence of convergents via continued fraction expansion 
# and generation of the p and q terms, checking for whether they satisfy the equation.
# Note the need for very high precision due to some number (e.g., 151) having very 
# long cycle length


import sys
import math
import decimal


# returns the continued fraction sequence of sqrt(d), and assumed to repeat restarting with the second number
def cf(d):
	s = decimal.Decimal(d).sqrt()
	r = decimal.Decimal(s)
	I = 0
	ret = []
	
	while I < 2 * math.floor(s):
		I = math.floor(r)
		ret.append(I)
		r = decimal.Decimal(1 / (r - I))
		
	return ret
	
	
# verifies whether an (x,y) pair is a solution for Pell's equation for a given d
def verify_pell(d, x, y):
	if (x*x - d*y*y == 1):
		return True
	else:
		return False


decimal.getcontext().prec = 100
s = 2		
maxd = -1
maxp = -1
maxq = -1
for d in range(2, 1001):
	if (s * s == d):
		s = s + 1
		continue
	continued = cf(d)
	period = len(continued) - 1	
	
	# once we know the entire continued fraction sequence, we can generate p and q, where p/q are 
	# convergents of sqrt(d)
	n = 0
	while True:
		if (n == 0):
			pnew = continued[0]
			qnew = 1
		elif (n == 1):
			pnew = continued[0] * continued[1] + 1
			qnew = continued[1]
			pold = continued[0]
			qold = 1
		else:
			tp = pnew
			tq = qnew
			pnew = pnew * continued[((n - 1) % period) + 1] + pold
			qnew = qnew * continued[((n - 1) % period) + 1] + qold
			pold = tp
			qold = tq
			
		if (verify_pell(d, pnew, qnew)):
			if (pnew > maxp):
				maxd = d
				maxp = pnew
				maxq = qnew
			#print("Found {0},{1} for {2}".format(pnew, qnew, d))
			break
		
		n = n + 1

print("Minimum for D <= 1000 is {0}, with solution {1},{2}".format(maxd, maxp, maxq))	