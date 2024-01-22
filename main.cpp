#include <iostream>
#include <vector>
#include <string>
#include <array>

using namespace std;

const int maxTodos = 8;
int todosIds[] = {};
string todosNames[] = {};

void showTodos(int todosIds[], string todosNames[], int length)
{
    if (length < 1)
    {
        cout << "No todos tasks. \n";
        return;
    }

    cout << "Todos Tasks \n";

    for (int i = 0; i < length; i++)
    {
        const string todoTask = todosNames[i];
        const int todoId = todosIds[i];
        cout << (todoId) << ". " << todoTask << "\n";
    }
}

string responseTask()
{
    cout
        << "Do you want to add a new todo? (Y/N): ";
    string response;
    cin >> response;
    return response;
}

void addTask(int todosIds[], string todosNames[], int todoLength)
{
    if (todoLength < maxTodos)
    {
        cout << "Enter the new todo task: ";
        string newTodo;
        cin.ignore();
        getline(cin, newTodo);

        todosIds[todoLength + 1] = todoLength + 1;
        todosNames[todoLength + 1] = newTodo;
        todoLength += 1;
        showTodos(todosIds, todosNames, todoLength); // This isnt being executed
    }
    else
    {
        cout << "Maximum number of todos reached.\n";
    }
}

int main()
{
    int todoLength = sizeof(todosIds) / sizeof(int);
    bool keepRunning = true;

    showTodos(todosIds, todosNames, todoLength);

    while (keepRunning)
    {
        string response = responseTask();
        if (response == "n" || response == "N")
        {
            keepRunning = false;
            break;
        }
        addTask(todosIds, todosNames, todoLength);
    }

    return 0;
}
