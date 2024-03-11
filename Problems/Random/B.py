import pandas as pd
from scipy.stats import shapiro, mannwhitneyu, ttest_ind, chi2_contingency
def work(df):
    numerical_vars = []
    categorical_vars = []
    for col in df.columns:
        if col == "death":
            continue
        if df[col].dtype == "int64":
            categorical_vars.append(col)
        else:
            numerical_vars.append(col)

    chi = []
    mann = []
    ttest = []
    shapiros = []

    for var in categorical_vars:
        contingency_table = pd.crosstab(df[var], df['death'])
        _, p, _, _ = chi2_contingency(contingency_table)
        chi.append((var, p))

    for var in numerical_vars:
        group1 = df[df['death'] == 0][var]
        group2 = df[df['deatsh'] == 1][var]

        _, p1 = shapiro(group1)
        _, p2 = shapiro(group2)

        shapiros.append((var, (p1, p2)))

        if p1 > 0.05 and p2 > 0.05:
            _, p = ttest_ind(group1, group2, equal_var=False)
            ttest.append((var, p))
        else:
            _, p = mannwhitneyu(group1, group2)
            mann.append((var, p))
    
    return {
        "mann_whitney": mann,
        "ttest": ttest,
        "chi_square": chi,
        "shapiro_wilk": shapiros
    }