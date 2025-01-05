def main_menu():
    print("\n=== To-Do List Manager ===")
    print("1. Add Task")
    print("2. View Tasks")
    print("3. Mark Task as Complete")
    print("4. Delete Task")
    print("5. Exit")

def add_task(tasks):
    task_name = input("Enter task name: ")
    due_date = input("Enter due date (optional): ")
    tasks.append({"name": task_name, "due_date": due_date, "completed": False})
    print("Task added!")

def view_tasks(tasks):
    print("\n--- To-Do List ---")
    for i, task in enumerate(tasks, 1):
        status = "✓" if task["completed"] else " "
        due_date = f" (Due: {task['due_date']})" if task["due_date"] else ""
        print(f"{i}. {task['name']}{due_date} [{status}]")

def mark_complete(tasks):
    view_tasks(tasks)
    task_num = int(input("Enter task number to mark as complete: ")) - 1
    if 0 <= task_num < len(tasks):
        tasks[task_num]["completed"] = True
        print("Task marked as complete!")
    else:
        print("Invalid task number.")

def delete_task(tasks):
    view_tasks(tasks)
    task_num = int(input("Enter task number to delete: ")) - 1
    if 0 <= task_num < len(tasks):
        tasks.pop(task_num)
        print("Task deleted!")
    else:
        print("Invalid task number.")

if __name__ == "__main__":
    tasks = []
    while True:
        main_menu()
        choice = input("Choose an option: ")
        if choice == "1":
            add_task(tasks)
        elif choice == "2":
            view_tasks(tasks)
        elif choice == "3":
            mark_complete(tasks)
        elif choice == "4":
            delete_task(tasks)
        elif choice == "5":
            print("Goodbye!")
            break
        else:
            print("Invalid choice. Please try again.")
