#include <iostream>
using namespace std;

void print_template(int sudoku[9][9])
{
    for (int row = 0; row < 9; row++){
        for (int col = 0; col < 9; col++)
            cout << sudoku[row][col] << " ";
        cout << endl;
    }
}

bool Find_Unassigne_Location(int sudoku[9][9],int& row, int& col)
{
    for (row = 0; row < 9; row++)
        for (col = 0; col < 9; col++)
            if (sudoku[row][col] == 0)
                return true;
    return false;
}

bool Used_In_Col(int sudoku[9][9], int col, int num)
{
    for (int row = 0; row < 9; row++)
        if (sudoku[row][col] == num)
            return true;
    return false;
}

bool Used_In_Box(int sudoku[9][9], int boxStartRow, int boxStartCol, int num)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (sudoku[row + boxStartRow][col + boxStartCol] == num)
                return true;
    return false;
}

bool Used_In_Row(int sudoku[9][9], int row, int num)
{
    for (int col = 0; col < 9; col++)
        if (sudoku[row][col] == num)
            return true;
    return false;
}

bool solve_sudoku(int sudoku[9][9]){
    int row, col;
    if (!Find_Unassigne_Location(sudoku, row, col))
        return true;

    for (int num = 1; num <= 9; num++)
    {
        if (!Used_In_Row(sudoku, row, num) && !Used_In_Col(sudoku, col, num) && !Used_In_Box(sudoku, row - row % 3, col - col % 3, num) && sudoku[row][col] == 0)
        {
            sudoku[row][col] = num;
            if (solve_sudoku(sudoku))
                return true;
            sudoku[row][col] = 0;
        }
    }
    return false;
}

int main()
{
    int sudoku_1[9][9] = { { },
                        {  },
                        {  },
                        {  },
                        {  },
                        {  },
                        {  },
                        {  },
                        {  } };

    int sudoku_2[9][9] = { {  },
                        {  },
                        {  },
                        {  },
                        {  },
                        {  },
                        {  },
                        {  },
                        {  } };

    print_template(sudoku_1);
    solve_sudoku(sudoku_1);
    cout << "Solution" << "\n";
    print_template(sudoku_1);
    cout << "\n";

    print_template(sudoku_2);
    solve_sudoku(sudoku_2);
    cout << "Solution" << "\n";
    print_template(sudoku_2);

    return 0;
}
