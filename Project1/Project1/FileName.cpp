#include <iostream>
#include <string>

using namespace std;

int main() {

    int seats[3][5][4] = { 0 };

    const int ADULT_FARE = 25000;
    const int YOUTH_FARE = 18000;

    int totalAdult = 0;
    int totalYouth = 0;

    int choice = 0;


    while (true) {
        // �ʱ� ȭ��
        cout << "** ���� ���� �ý��� **" << endl;
        cout << "1. �¼� ���� �ý���" << endl;
        cout << "2. ���� ����" << endl;
        cout << "3. ���α׷� ����" << endl;
        cout << "��ȣ�� �Է��ϼ��� : ";
        cin >> choice;
        cout << endl << endl << endl;

        // �¼� ���� �ޱ�
        if (choice == 1) {
            // �¼� ���
            for (int car = 0; car < 3; car++) {
                cout << "1 2\t3 4 (" << car + 1 << "ȣ��)" << endl;
                cout << "-----------" << endl;

                for (int row = 0; row < 5; row++) {
                    cout << seats[car][row][0] << " " << seats[car][row][1] << "\t";
                    cout << seats[car][row][2] << " " << seats[car][row][3] << endl;
                }

                cout << "-----------" << endl << endl;
            }

            // ���� �ο� �Է�
            int adult, youth;
            cout << "����(25000��): " ;
            cin >> adult;
            cout << endl;
            cout << "û�ҳ�(18000��): " ;
            cin >> youth;
            cout << endl;

            totalAdult += adult;
            totalYouth += youth;

            // �� �ο� ����ŭ �¼� ����
            int totalPassengers = adult + youth;
            int remainingPassengers = totalPassengers;

            while (remainingPassengers > 0) {
                int car, row, col;

                cout << "��ȣ���� ���� �Ͻðڽ��ϱ�?" << endl;
                cin >> car;

                // ���� ������ ȣ������ Ȯ��
                if (car < 1 || car > 3) {
                    cout <<"���డ���� ȣ���� �ƴմϴ�." << endl << endl;
                    continue;
                }

                cout << "�, ���° �¼��� �����Ͻðڽ��ϱ�?" << endl;
                cin >> col >> row;

                // �¼� ���� Ȯ��
                if (row < 1 || row > 5 || col < 1 || col > 4) {
                    cout << "���డ���� �¼��� �ƴմϴ�." << endl << endl;
                    continue;
                }

                // �̹� ����� �ڸ����� Ȯ��
                if (seats[car - 1][row - 1][col - 1] == 1) {
                    cout << "�̹� ����Ǿ����ϴ�. �ٸ� �ڸ��� �����ϼ���" << endl << endl;
                    continue;
                }

                // ���� ó��
                seats[car - 1][row - 1][col - 1] = 1;
                remainingPassengers--;
                cout << endl << "����Ǿ����ϴ�." << endl << endl;


                if (remainingPassengers == 0) {
                    for (int car = 0; car < 3; car++) {
                        cout << "1 2\t3 4 (" << car + 1 << "ȣ��)" << endl;
                        cout << "-----------" << endl;

                        for (int row = 0; row < 5; row++) {
                            cout << seats[car][row][0] << " " << seats[car][row][1] << "\t";
                            cout << seats[car][row][2] << " " << seats[car][row][3] << endl;
                        }

                        cout << "-----------" << endl;
                    }
                }
            }
        }
        // ���� ����
        else if (choice == 2) {
            // ���� �¼� ���� ���
            for (int car = 0; car < 3; car++) {
                cout << "1 2\t3 4 (" << car + 1 << "ȣ��)" << endl;
                cout << "-----------" << endl;

                for (int row = 0; row < 5; row++) {
                    cout << seats[car][row][0] << " " << seats[car][row][1] << "\t";
                    cout << seats[car][row][2] << " " << seats[car][row][3] << endl;
                }

                cout << "-----------" << endl;
            }

            // ������ �¼� �� �Է�
            int changeCount;
            cout << "�ٲ� �¼��� ������ �Է��ϼ���: ";
            cin >> changeCount;

            for (int i = 0; i < changeCount; i++) {
                int currentCar, currentRow, currentCol;
                int newCar, newRow, newCol;

                while (true) {
                    cout << "���� �¼��� �ٲ� �¼��� �Է��ϼ���" << endl;
                    cout << "���� �¼�(Hȣ��, N��, M�� °): ";
                    cin >> currentCar >> currentCol >> currentRow;

                    // ���� �¼� ���� Ȯ��
                    if (currentCar < 1 || currentCar > 3 || currentRow < 1 || currentRow > 5 || currentCol < 1 || currentCol > 4) {
                        cout << "�¼� ��ȣ�� �ٽ� �Է����ּ���" << endl;
                        continue;
                    }

                    // ���� �¼��� ����Ǿ� �ִ��� Ȯ��
                    if (seats[currentCar - 1][currentRow - 1][currentCol - 1] != 1) {
                        cout << "���� �¼��� Ʋ�Ƚ��ϴ�. �ٽ� �Է����ּ���" << endl;
                        continue;
                    }

                    cout << "���� �¼�(Hȣ��, N��, M�� °): ";
                    cin >> newCar >> newCol >> newRow;

                    // �� �¼� ���� Ȯ��
                    if (newCar < 1 || newCar > 3 || newCol < 1 || newCol > 5 || newRow < 1 || newRow > 4) {
                        cout << "�¼� ��ȣ�� �ٽ� �Է����ּ���" << endl;
                        continue;
                    }

                    // ���� �¼����� Ȯ��
                    if (currentCar == newCar && currentRow == newRow && currentCol == newCol) {
                        cout << "�Ȱ��� �ڸ� �Դϴ�. �ٸ� �¼��� �����ϼ���" << endl;
                        continue;
                    }

                    // �� �¼��� �̹� ����Ǿ� �ִ��� Ȯ��
                    if (seats[newCar - 1][newRow - 1][newCol - 1] == 1) {
                        cout << "�̹� ����Ǿ����ϴ�. �ٸ� �¼��� �����ϼ���" << endl;
                        continue;
                    }

                    // �¼� ���� ó��
                    seats[currentCar - 1][currentRow - 1][currentCol - 1] = 0;
                    seats[newCar - 1][newRow - 1][newCol - 1] = 1;
                    cout << "����Ǿ����ϴ�." << endl;
                    break;
                }
            }

            // ���� �� �¼� ���� ���
            for (int car = 0; car < 3; car++) {
                cout << "1 2\t3 4 (" << car + 1 << "ȣ��)" << endl;
                cout << "-----------" << endl;

                for (int row = 0; row < 5; row++) {
                    cout << seats[car][row][0] << " " << seats[car][row][1] << "\t";
                    cout << seats[car][row][2] << " " << seats[car][row][3] << endl;
                }

                cout << "-----------" << endl;
            }
        }
        
        else if (choice == 3) {
            // �� �ݾ� ���
            int totalPrice = (totalAdult * ADULT_FARE) + (totalYouth * YOUTH_FARE);
            cout << "�� " << totalPrice << "�� �Դϴ�." << endl;
            break;
        }
    }

    return 0;
}