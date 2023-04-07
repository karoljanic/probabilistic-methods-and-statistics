from random import uniform as rand
import math
from simulation_framework import Simulation


def approximate_pi() -> None:
    """
    Simulation of approximating PI

    :return: None
    """
    sim = Simulation(list(range(100, 10000, 100)), 50,
                     lambda n:
                     sum([math.sqrt(pow(rand(-1, 1), 2) + pow(rand(-1, 1), 2)) <= 1
                          for _ in range(n)]) / n * 4)

    sim.add_series_to_chart()
    sim.add_averages_to_chart(label='average value', marker_size=20)
    sim.add_line(lambda x: math.pi, label='exact value', marker_size=3)
    sim.add_names('Points number used in approximating', 'Approximated $\pi$ value', 'Approximating $\pi$')
    sim.add_legend()
    sim.generate_chart('pi generating')
