import matplotlib.pyplot as plt
import os


class Simulation:
    """ Class generating and managing a simulation """
    def __init__(self, n_values, repeats, fun):
        """
        Constructor

        :param n_values: numbers of points for which simulation is carried out
        :type n_values: list of int
        :param repeats: simulation repeats number
        :type repeats: int
        :param fun: function calculating simulation value for given number of points
        :type fun: (int) -> float
        """
        self.reps = repeats
        self.x_values = n_values.copy()
        self.y_series = [[fun(n) for _ in range(repeats)] for n in n_values]

    def add_series_to_chart(self, label='', color='b', marker='s', marker_size=10) -> None:
        """
        Adding calculated series to chart

        :param label: series label
        :type label: str
        :param color: marker color
        :type color: str
        :param marker: marker shape type
        :type marker: str
        :param marker_size: marker size
        :type marker_size: int
        :return: None
        """
        for rep in range(self.reps):
            plt.scatter(self.x_values, [s[rep] for s in self.y_series],
                        label=label, color=color, marker=marker, s=marker_size)

    def add_averages_to_chart(self, label='', color='r', marker='s', marker_size=10) -> None:
        """
        Adding series representing calculated averages to chart

        :param label: series label
        :type label: str
        :param color: marker color
        :type color: str
        :param marker: marker shape type
        :type marker: str
        :param marker_size: marker size
        :type marker_size: int
        :return: None
        """
        plt.scatter(self.x_values, [sum(s) / len(s) for s in self.y_series],
                    label=label, color=color, marker=marker, s=marker_size)

    def add_line(self, fun, label='', color='y', marker='s', marker_size=10) -> None:
        """
        Adding additional series representing given function to chart

        :param fun: function representing series
        :type fun: (int) -> float
        :param label: series label
        :type label: str
        :param color: marker color
        :type color: str
        :param marker: marker shape type
        :type marker: str
        :param marker_size: marker size
        :type marker_size: int
        :return: None
        """
        plt.scatter(self.x_values, [fun(x) for x in self.x_values], color=color, marker=marker, s=marker_size, label=label)

    def add_names(self, x_axis_name, y_axis_name, title_name) -> None:
        """
        Adding chart description

        :param x_axis_name: X axis description
        :type x_axis_name: str
        :param y_axis_name: Y axis description
        :type y_axis_name: str
        :param title_name: chart title
        :type title_name: str
        :return: None
        """
        plt.xlabel(x_axis_name)
        plt.ylabel(y_axis_name)
        plt.title(title_name)

    def add_legend(self, location='upper right') -> None:
        """
        Showing chart legend

        :param location: legend location on chart
        :type location: str
        :return: None
        """
        plt.legend(loc=location)

    def generate_chart(self, result_file_name) -> None:
        """
        Saving generated chart to plots directory as PNG and showing it

        :param result_file_name: name of saved file
        :type result_file_name: str
        :return: None
        """
        plt.savefig(os.path.dirname(os.path.abspath(__file__)) + '/plots/' + result_file_name + '.png')
        plt.show()
