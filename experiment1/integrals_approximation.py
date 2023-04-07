from random import uniform as rand
from simulation_framework import Simulation


def approximate_function_integral(fun, fun_name, var_name, lower_bound, upper_bound, supremo, calc_value) -> None:
    """
    Simulation of approximating integral of given function

    :param fun: function to approximate
    :type fun: (float) -> float
    :param fun_name: string of function name in latex format
    :type fun_name: str
    :param var_name: variable name
    :type var_name: str
    :param lower_bound: lower bound of integration
    :type lower_bound: float
    :param upper_bound: upper bound of integration
    :type upper_bound: float
    :param supremo: supremo of the function on [lower_bound, upper_bound]
    :type supremo: float
    :param calc_value: exact value of function integral
    :type calc_value: float
    :return: None
    """
    sim = Simulation(list(range(50, 5000, 50)), 50,
                     lambda n:
                     sum([rand(0, supremo) <= fun(rand(lower_bound, upper_bound))
                         for _ in range(n)]) / n * (upper_bound - lower_bound) * supremo)

    sim.add_series_to_chart()
    sim.add_averages_to_chart(label='average value', marker_size=20)
    sim.add_line(lambda x: calc_value, label='exact value', marker_size=3)
    sim.add_names('Points number used in approximating', 'Approximated integral value',
                         'Approximating $\int_{}^{} {} \,d{}$'.format(lower_bound, upper_bound, fun_name, var_name))
    sim.add_legend()
    sim.generate_chart('integrate ' + fun_name)
