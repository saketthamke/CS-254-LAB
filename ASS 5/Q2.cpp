#include <bits/stdc++.h>

using namespace std;

class Vertex {
public:
    int cell;
    int moves;

    Vertex() : cell(0), moves(0) {}
};

void getLaddersAndSnakes(vector<int>& board) {
    int numLadders, numSnakes;
    cin >> numLadders >> numSnakes;

    for (int i = 0; i < numLadders; ++i) {
        int start, end;
        cin >> start >> end;
        board[start - 1] = end - 1;
    }

    for (int i = 0; i < numSnakes; ++i) {
        int head, tail;
        cin >> head >> tail;
        board[head - 1] = tail - 1;
    }
}

int findMinMoves(vector<int>& board) {
    int size = board.size();
    vector<bool> visited(size, false);

    deque<Vertex> queue;
    Vertex vertex;
    vertex.cell = 0;
    vertex.moves = 0;
    queue.push_back(vertex);
    visited[0] = true;

    while (!queue.empty()) {
        vertex = queue.front();
        queue.pop_front();
        int cellNum = vertex.cell;

        if (cellNum == size - 1) {
            break;
        }

        for (int i = cellNum + 1; i <= min(cellNum + 6, size - 1); ++i) {
            if (!visited[i]) {
                Vertex currentVertex;
                currentVertex.moves = vertex.moves + 1;
                visited[i] = true;

                if (board[i] == -1) {
                    currentVertex.cell = i;
                } else {
                    currentVertex.cell = board[i];
                }

                queue.push_back(currentVertex);
            }
        }
    }

    return vertex.moves;
}

int main() {
    
    int t; 
    cin>>t;
    while(t--){

        int size; 
        cin >> size;

        vector<int> board(size, -1);
        getLaddersAndSnakes(board);

        cout << findMinMoves(board) << endl;
    }

    return 0;
}