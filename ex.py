import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit
import numpy.polynomial.polynomial as P
import seaborn as sns

def linear_fit(x, a, b):
    return a + b*x**(1.5)

"""
U = [0.1, 0.2, 0.4, 0.8, 1.4, 2]
Fd = [0.0929, 0.204, 0.571, 1.35, 2.03, 2.91]
param, cov = curve_fit(linear_fit, U, Fd)
print("Fd= " + str(param[0])+" + " + str(param[1]) + " U^1.5")
"""

def linear_fit2(x, b):
    return b*x**3

Fd = [0.0124, 0.0369, 0.140, 0.323, 0.455, 0.572, 0.608, 0.839]
phi = [0.2, 0.4, 0.6, 0.7, 0.75, 0.8, 0.85, 0.9]

fig1 = plt.figure()
plt.plot(phi, Fd, ls="", marker="o")
param, cov = curve_fit(linear_fit2, phi, Fd)
print("Fd= " + str(param[0])+ "* x^3)")

y1 = []
for i in np.arange(0, 1, 0.02):
    y1.append(param[0]*i**3)

plt.plot(np.arange(0.0, 1.0, 0.02), y1)
plt.xlabel("充填率")
plt.ylabel("抗力")
fig1.savefig("Fd_phi3"+".png")


plt.show()





