#include "header.h"
#include "Tea_Cou_Data.h"
#include "Max_match.h"




int main() {
    Tea_Cou_Data TCData;
    Max_match PiPei;
    int i;
    cout<<endl<<endl<<endl;
    while (true)
    {
        //system("cls");
        cout<<"0.Import from file"<<endl;
        cout<<"1.Add teacher"<<endl;
        cout<<"2.Add courses"<<endl;
        cout<<"3.Add teacher to course relationship"<<endl;
        cout<<"4.Output maximum number of matches"<<endl;
        cout<<"5.Output a match result"<<endl;
        cout<<"6.Delete the relation between teacher and course"<<endl;
        cout<<"7.Delete teacher"<<endl;
        cout<<"8.Delete course"<<endl;
        cout<<"9.Print all data"<<endl;
        cout<<"10.Exit"<<endl;
        cout<<"Enter your operation number:";
        cin>>i;
        cout<<endl;
        switch(i)
        {
            case 0:
                TCData.importdata();
                break;
            case 1:
                TCData.Add_Teacher();
                break;
            case 2:
                TCData.Add_Course();
                break;
            case 3:
                TCData.link_node();
                break;
            case 4:
                cout<<"Maximum number of matches:"<<PiPei.hungary_algorithnm(TCData)<<endl<<endl;
                break;
            case 5:
                PiPei.show_result(TCData);
                cout<<endl;
                break;
            case 6:
                TCData.delete_relationship();
                break;
            case 7:
                TCData.delete_teacher();
                break;
            case 8:
                TCData.delete_courses();
                break;
            case 9:
                TCData.Show_teacherandcourse();
                cout<<endl;
                break;
            case 10:
                system("cls");
                exit(0);
            default:
                cout<<"Input is out of range"<<endl;

        }
        //system("pause");
        //system("cls");
    }

    return 0;
}