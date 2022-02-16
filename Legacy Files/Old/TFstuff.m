syms x(t) u(t) k m c
x1d = diff(x(t), t)

sys_x2d = (1/m)*(u(t) - k*x(t) - c*x1d)
G = laplace(sys_x2d)