import numpy as np
import pandas as pd

class CheckIndependence:
    def __init__(self):
        self.version = 1

    def check_independence(self, distr_table: pd.DataFrame):
        # Calculate the marginal probabilities
        px = distr_table.groupby("X")["pr"].sum()
        py = distr_table.groupby("Y")["pr"].sum()

        joint = pd.merge(
            distr_table,
            px.rename("px"),
            on = "X"
        )
        joint = pd.merge(
            joint,
            py.rename("py"),
            on="Y"
        )

        joint["independent"] = np.isclose(joint["pr"], joint["px"] * joint["py"])

        joint["x_mean"] = joint["X"] * joint["pr"]
        joint["y_mean"] = joint["Y"] * joint["pr"]
        mux = joint["x_mean"].sum()
        muy = joint["y_mean"].sum()
        joint["cov"] = (joint["X"] - mux) * (joint["Y"] - muy) * joint["pr"]
        covariance = joint["cov"].sum()

        joint["x_var"] = ((joint["X"] - mux) ** 2) * joint["pr"]
        joint["y_var"] = ((joint["Y"] - muy) ** 2) * joint["pr"]
        sigma_x = np.sqrt(joint["x_var"].sum())
        sigma_y = np.sqrt(joint["y_var"].sum())
        correlation = covariance / (sigma_x * sigma_y)

        return {
            "are_independent": bool(joint["independent"].all()),
            "cov": covariance,
            "corr": correlation
        }

# Example usage
distr_table = pd.DataFrame({
    'X': [0, 0, 1, 1],
    'Y': [1, 2, 1, 2],
    'pr': [0.3, 0.25, 0.15, 0.3]
})

checker = CheckIndependence()
result = checker.check_independence(distr_table)
print(result)