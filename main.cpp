

#include <iostream>
#include <vector>
#include <string>
#include <array>

using namespace std;

const int maxTodos = 8;

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

int main()
{
    int todosIds[] = {};
    string todosNames[] = {};
    int todoLength = sizeof(todosIds) / sizeof(int);
    bool keepRunning = true;

    showTodos(todosIds, todosNames, todoLength);

    cout
        << "Do you want to add a new todo? (Y/N): ";
    char response;
    cin >> response;

    if (response == 'Y' || response == 'y')
    {
        if (todoLength < maxTodos)
        {
            cout << "Enter the new todo task: ";
            string newTodo;
            cin.ignore();
            getline(cin, newTodo);

            cout << "New todo added: " << newTodo << "\n";
            todosIds[todoLength] = todoLength + 1;
            todosNames[todoLength] = newTodo;
            todoLength += 1;
            showTodos(todosIds, todosNames, todoLength); // This isnt being executed
        }
        else
        {
            cout << "Maximum number of todos reached.\n";
        }
    }
    else if (response == 'N' || response == 'n')
    {
        cout << "Okay bye.\n";
    }
    else
    {
        cout << "Invalid input.\n";
    }

    return 0;
}