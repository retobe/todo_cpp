#include <iostream>
#include <string>

using namespace std;

const int maxTodos = 8;
int todosIds[maxTodos] = {};
string todosNames[maxTodos] = {};
int todoLength = 0;

void showTodos()
{
    if (todoLength < 1)
    {
        cout << "No todos tasks. \n";
        return;
    }

    cout << "Todos Tasks \n";

    for (int i = 0; i < todoLength; i++)
    {
        const string todoTask = todosNames[i];
        const int todoId = todosIds[i];
        cout << (todoId == 0 ? 1 : todoId) << ". " << todoTask << "\n";
    }
}

int responseTask()
{
    cout << "\n\nWrite down what you want to do\nAdd Task - 1\nRemove Task - 2\nUpdate Task - 3\nExit Todo Manager - 4\nResponse: ";
    int response;
    cin >> response;
    return response;
}

int findTodoIndex(int queryId)
{
    for (int i = 0; i < todoLength; i++)
    {
        if (todosIds[i] == queryId)
        {
            return i;
        }
    }
    return -1;
}

void updateTask()
{
    if (todoLength < 1)
    {
        return;
    }
    int todoId;
    string newTodoName;

    cout << "Write down the ID of the TODO: ";
    cin >> todoId;

    cin.ignore();

    cout << "Write down the new Todo-Task (name): ";
    getline(cin, newTodoName);

    int elementID = findTodoIndex(todoId);

    if (elementID != -1)
    {
        todosNames[elementID] = newTodoName;

        cout << "Todo updated successfully.\n";
    }
    else
    {
        cout << "Todo not found.\n";
    }
}

void addTask()
{
    if (todoLength < maxTodos)
    {
        cout << "Enter the new todo task: ";
        string newTodo;
        cin.ignore();
        getline(cin, newTodo);

        todosIds[todoLength] = todoLength + 1;
        todosNames[todoLength] = newTodo;
        todoLength += 1;
    }
    else
    {
        cout << "Maximum number of todos reached.\n";
    }
}

void removeTask()
{
    if (todoLength < 1)
    {
        return;
    }
    cout << "Write down the ID of the TODO: ";
    int todoId;
    cin >> todoId;
    int elementID = findTodoIndex(todoId);

    if (elementID != -1)
    {
        for (int i = elementID; i < todoLength - 1; i++)
        {
            todosIds[i] = todosIds[i + 1];
            todosNames[i] = todosNames[i + 1];
        }

        todoLength--;

        cout << "Todo removed successfully.\n";
    }
    else
    {
        cout << "Todo not found.\n";
    }
}

int main()
{
    bool keepRunning = true;

    showTodos();

    while (keepRunning)
    {
        int response = responseTask();

        if (response == 1)
        {
            addTask();
            showTodos();
        }
        else if (response == 2)
        {
            removeTask();
            showTodos();
        }
        else if (response == 3)
        {
            updateTask();
            showTodos();
        }
        else if (response == 4)
        {
            keepRunning = false;
        }
        else
        {
            cout << "Invalid option. Please choose a valid option.\n";
        }
    }

    return 0;
}
