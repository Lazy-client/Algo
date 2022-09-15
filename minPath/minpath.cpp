//
// Created by 15776 on 2022/5/17.
//
// ��������
const int direction[4][2] = {{0,  1},
                             {-1, 0},
                             {0,  -1},
                             {1,  0}};

const int MAXM = 100, MAXN = 100, QUEUE_LENGTH = 5;

// �����еĽڵ�
struct Node {
    int x, y, distance;

    Node() {}

    Node(int xx, int yy, int d) : x(xx), y(yy), distance(d) {}
};

int n, m, step = 0, map[MAXM][MAXN], visit[MAXM][MAXN];
Node start, target;


void bfs() {
    Node queue[QUEUE_LENGTH];
    int head = 0, tail = 1;
    queue[0] = Node(start.x, start.y, 0);
    visit[start.x][start.y] = 0;

    while (head != tail) {
        int x = queue[head].x;
        int y = queue[head].y;
        int distance = queue[head].distance;
        head = (head + 1) % QUEUE_LENGTH;
        for (int i = 0; i < 4; ++i) {
            int dx = x + direction[i][0];
            int dy = y + direction[i][1];
            if (dx >= 0 && dx < m && dy >= 0 && dy < n && visit[dx][dy] == -1 && map[dx][dy] >= 0) {
                // ��ʾ��i�����߹����ģ������������·��
                visit[dx][dy] = i;
                if (dx == target.x && dy == target.y) {
                    cout << "�ѵ�Ŀ��㣬��̾���Ϊ" << distance + 1 << endl;
                    step = distance + 1;
                    return;
                }
                if ((tail + 1) % QUEUE_LENGTH == head) {
                    cout << "������" << endl;
                    return;
                }
                // ���������
                queue[tail] = Node(dx, dy, distance + 1);
                tail = (tail + 1) % (QUEUE_LENGTH);
            }
        }
    }
}

void printPath() {
    int x, y, d, path[MAXM][MAXN] = {0};
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            path[i][j] = -1;
        }
    }
    x = target.x;
    y = target.y;
    path[start.x][start.y] = 0;
    // ·������
    while (!(x == start.x && y == start.y)) {
        path[x][y] = step--;
        d = visit[x][y];
        x -= direction[d][0];
        y -= direction[d][1];
    }
    // ·����ӡ
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (path[i][j] >= 0) {
                cout << path[i][j];
            } else {
                cout << "-";
            }
        }
        cout << endl;
    }
}
