import calendar
import random

# Function to calculate total income
def calculate_total_income(income_list):
    total_income = sum(income_list)
    total_income = round(total_income, 2)
    return total_income

# Function to calculate total expenses
def calculate_total_expenses(expenses_list):
    total_expenses = sum(expenses_list)
    total_expenses = round(total_expenses, 2)
    return total_expenses

# Function to calculate remaining budget
def calculate_remaining_budget(total_income, total_expenses):
    remaining_budget = total_income - total_expenses
    remaining_budget = round(remaining_budget, 2)
    return remaining_budget

# Variables
current_month = 1
months = list(calendar.month_name)[1:]  # List of month names

# Lists
income_list = []
expense_list = []

# Function to get input for a category
def get_category_input(category_type, index):
    name = input(f"Enter {category_type} {index + 1}'s name: ")
    amount = float(input(f"Enter monthly {category_type} amount for {name}: "))
    return name, amount

# Function to track finances for a specific month
def track_finances_for_month(month):
    global current_month
    current_month = month

    print(f"\n--- {months[current_month - 1]} Financial Tracking ---")

    # Get user input for incomes
    num_incomes = int(input("Enter the number of incomes: "))
    income_list = [get_category_input("income", i) for i in range(num_incomes)]

    # Get user input for expenses
    num_expenses = int(input("Enter the number of expenses: "))
    expense_list = [get_category_input("expense", i) for i in range(num_expenses)]

    # Calculate total income and total expenses
    total_income = calculate_total_income([income for _, income in income_list])
    total_expenses = calculate_total_expenses([expense for _, expense in expense_list])

    # Calculate remaining budget
    remaining_budget = calculate_remaining_budget(total_income, total_expenses)

    # Print the financial summary
    print("\n----- Financial Summary -----")
    print(f"Total Income: ${total_income:.2f}")
    print(f"Total Expenses: ${total_expenses:.2f}")
    print(f"Remaining Budget: ${remaining_budget:.2f}")

    # Budget Adjustment Section
    adjust_budget = input("Do you want to adjust your budget? (yes/no): ").lower()
    if adjust_budget == "yes":
        for category_type, category_list in [("income", income_list), ("expense", expense_list)]:
            for i, (name, amount) in enumerate(category_list):
                adjustment = float(input(f"Enter the new amount for {category_type} '{name}' in {months[current_month - 1]}: "))
                category_list[i] = (name, amount + adjustment)

        # Recalculate total income and total expenses
        total_income = calculate_total_income([income for _, income in income_list])
        total_expenses = calculate_total_expenses([expense for _, expense in expense_list])

        # Recalculate remaining budget
        remaining_budget = calculate_remaining_budget(total_income, total_expenses)

        # Print the updated financial summary
        print("\n----- Updated Financial Summary -----")
        print(f"Total Income: ${total_income:.2f}")
        print(f"Total Expenses: ${total_expenses:.2f}")
        print(f"Remaining Budget: ${remaining_budget:.2f}")

# Main function
if __name__ == "__main__":
    while True:
        user_month = int(input("Enter the month (1-12) for financial tracking (or 0 to exit): "))
        if user_month == 0:
            break
        elif 1 <= user_month <= 12:
            track_finances_for_month(user_month)
        else:
            print("Invalid month. Please enter a number between 1 and 12.")
