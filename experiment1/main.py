from integrals_approximation import approximate_function_integral
from pi_approximation import approximate_pi
from math import pow, sin, pi

approximate_function_integral(lambda x: pow(x, 3), 'x^{3}', 'x', 1, 3, 27, 20)

approximate_function_integral(lambda x: pow(x, 1/3), '\sqrt[3]{x}', 'x', 0, 8, 2, 12)
approximate_function_integral(lambda x: sin(x), 'sin(x)', 'x', 0, pi, 1, 2)
approximate_function_integral(lambda x: 4 * x * pow(1 - x, 3), '4x(1-x)^3', 'x', 0, 1, 0.5, 0.2)

approximate_pi()
