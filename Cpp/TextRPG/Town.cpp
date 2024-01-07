#include "Town.h"
#include <iostream>
#include <conio.h>
#include "Player.h"

void Town::WeaponUp(Player& _Player)
{
    while (true)
    {
        system("cls");

        int EquipUp = _Player.Weapon.GetEquipUp();

        _Player.StatusRender();
        printf_s("---------------------------------------\n");
        printf_s("��ȭ��ġ %d\n", EquipUp);
        printf_s("---------------------------------------\n");
        printf_s("1. ��ȭ\n");
        printf_s("2. ������\n");

        int Select = _getch();


        switch (Select)
        {
        case '1':
        {
            int EquipUpGold = (EquipUp + 1) * 1000;

            if (EquipUpGold > _Player.GetGold())
            {
                printf_s("���� �����Ͽ� ��ȭ�� �Ҽ��� �����ϴ�.\n");
                int Test = _getch();
                break;
            }

            if (EquipUp >= 30)
            {
                printf_s("���� ��ȭ ���¶� ���̻� ��ȭ�� �����ϽǼ� �����ϴ�.\n");
                int Test = _getch();
                break;
            }

            // ���ⷯ ������ ��ȭ�� �Ҽ� �ִٰ� ����.
            _Player.AddGold(-EquipUpGold);

            int Random = rand() % 100;

            if (Random != 0)
            {
                _Player.Weapon.EquipLevelUp();
                printf_s("��ȭ�� �����߽��ϴ�.\n");
            }
            else if (Random == 0)
            {
                int CurEquipUp = _Player.Weapon.GetEquipUp();
                if (10 <= CurEquipUp && 20 >= CurEquipUp)
                {
                    _Player.Weapon.EquipLevelDown(5);
                }
                else if (20 <= CurEquipUp)
                {
                    _Player.Weapon.EquipLevelReset();
                }

                printf_s("��ȭ�� �����߽��ϴ�.\n");
            }
            int Test = _getch();
            break;
        }
        case '2':
            return;
        default:
            break;
        }
    }
    // �����е��� �ǵ���� �ϴ� �κ��� ���� ���Դϴ�.

    // 1. �÷��̾��� ������ ��ȭ ���¸� �����ش�.
    // ���� �׷����� �������� ���δ� �����.
    // 1���������� ��ȭ
    //   30���� ������ ����� ��ȭ�� �ȵȴٰ� �����.
    // 
    // 2���������� ������.

    // 2.��
    // 1������ 10�������� �����ص� ��ȭ��ġ�� �������� �ʽ��ϴ�.
    // 10������ 20�������� �����ϸ� ��ȭ��ġ�� 5�� �������ϴ�.
    // 20������ 30�������� �����ϸ� ��ȭ��ġ�� 0�� �˴ϴ�.
    // ��ȭȮ���� �������
}

void Town::Heal(Player& _Player)
{
    _Player.HpReset();

    // 1. �÷��̾ 
    // ��¥ ġ��ǰ� ������ּ���.
    // 
    // 2. ������� ���Ͱ� �׾��� �÷��̾
    // ������ HP�� �ٽ� ���� ���弼��.
    // 
    // 3. ���Ͱ� �׾�����
    //   �÷��̾ ��带 ��� �ϼ���
    //   ����� ������ �����ϰ� ���ϰ� �ϼ���
    //   100~500 <= ���ʿ�� ����.
    // 
    // 4. ��ȭ 1ȸ�� ��带 �Ҹ��ϰ� �ϼ���.
    //   ���� �����ϸ� ��ȭ�Ҽ� �����ϴ�. ��� �޼����� �߰��ϼ���.
    //   ��ȭ��ġ���� ��ȭ����� �����ϰ� �ϼ���.

    printf_s("�÷��̾�� ġ��Ǿ����ϴ�.");
    int Select = _getch();
}

void Town::In(Player& _Player)
{
    while (true)
    {
        _Player.StatusRender();
        printf_s("�������� ������ �Ͻðڽ��ϱ�.\n");
        printf_s("1. ��ȭ.\n");
        printf_s("2. ġ��.\n");
        printf_s("3. ������.\n");
        int Select = _getch();

        switch (Select)
        {
        case '1':
            WeaponUp(_Player);
            break;
        case '2':
            Heal(_Player);
            break;
        case '3':
            return;
        default:
            break;
        }

        system("cls");
    }

}
