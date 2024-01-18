// FIX THE SHOW TODOS FUNCTION!!!!!!!!!!
// Implement a plan on how you're going to do this.

#include <iostream>
#include <vector>
#include <string>
#include <array>

using namespace std;

void showTodos(int todosIds[], string todosNames[])
{
    const int todoLength = sizeof(todosIds) / sizeof(int);

    cout << "Todos Tasks \n";
    cout << todoLength;

    if (todoLength < 1)
    {
        cout << "No todos tasks.";
        return;
    }

    for (int i = 0; i < todoLength; i++)
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
    const int todoLength = sizeof(todosIds) / sizeof(int);
    const int todoNamesLength = sizeof(todosNames) / sizeof(int);
    bool keepRunning = true;

    showTodos(todosIds, todosNames);

    cout
        << "Do you want to add a new todo? (Y/N): ";
    char response;
    cin >> response;

    if (response == 'Y' || response == 'y')
    {
        // Add code here for when the user chooses 'Y' or 'y'
        cout << "Enter the new todo task: ";
        string newTodo;
        cin.ignore(); // Ignore the newline character left in the buffer
        getline(cin, newTodo);

        // Add the new todo to your data structures or perform other actions
        cout << "New todo added: " << newTodo << "\n";
        todosIds[todoLength + 1] = todosIds[todoLength] + 1;
        todosNames[todoNamesLength + 1] = newTodo;
    }
    else if (response == 'N' || response == 'n')
    {
        // Add code here for when the user chooses 'N' or 'n'
        cout << "Okay bye.\n";
        return 0;
    }
    else
    {
        cout << "Invalid input.\n";
        return 0;
    }

    return 0;
}