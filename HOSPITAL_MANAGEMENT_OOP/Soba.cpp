#include "Soba.h"


Soba::Soba():total_num(10)
{
    room_arr = new int*[10];
    for (int i = 0; i < 10; i++)
    {
        room_arr[i] = new int[10];
    }

    int c = 1;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            room_arr[i][j] = c;
            c++;
        }
    }

    room_arr[0][0] = 0;
    room_arr[0][1] = 0;


}

void Soba::free_room() {
    int count = 0;
    for (int i = 0; i < 10; i++)
    {

        for (int j = 0; j < 10; j++)
        {
            count++;
            if (count == free_r)
            {
                room_arr[i][j] = free_r;
                break;
            }
            //cout << count << " ";


        }
        //cout << endl;

    }

}
void Soba::set_free_r(int r)
{
    free_r = r;
    free_room();


}
istream& operator>>(istream& stream ,Soba& s)
{
    stream>>s.room_type;
    return stream;
}
ostream& operator<<(ostream& stream,Soba& s)
{
    stream<<s.room_type;
    return stream;
}

void Soba::display_rooms() {
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << room_arr[i][j] << " ";
        }
        cout << endl;
    }
}
int Soba::checK_room_avail(int input) {
    int check = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (room_arr[i][j] == input)
            {
                room_arr[i][j] = 0;
                check++;
                break;
            }
        }
    }
    return check;
}
Soba::~Soba()
{
}
