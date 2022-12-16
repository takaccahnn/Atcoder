import numpy as np
import math
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

Re_sampple = [11, 10 ,8.5, 6.5 ,5, 3, 7.25, 5.5, 4.5, 4, 3.5]
Cd_sample = [0.47043,0.5717,0.550536,0.5882,0.540131,0.433111,0.5864,0.57658,0.498955,0.49497,0.4858]

Re = np.array(Re_sampple)
Re *= 48/(25*math.pi)
Cd = np.array(Cd_sample)
Cd *= 100 * math.pi / 384


fig1 = plt.figure()
plt.plot(Re, Cd, ls="", marker="o", label="シュミレーション結果")
plt.yscale('log')
plt.xscale('log')

y1 = []
for i in np.arange(1.8, 9, 0.02):
    y1.append(24/i)

plt.plot(np.arange(1.8, 9.0, 0.02), y1, label="Cd=24/Re")

plt.xlabel("Re")
plt.ylabel("Cd")
plt.legend()
fig1.savefig("CdCompare"+".png")

plt.show()






