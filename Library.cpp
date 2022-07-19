#include<bits/stdc++.h>
#include<string>
using namespace std;


class Book{
 public : 
  string Title;
  string Author;
  string ISBN;
  string publication;
  
};

class Book_issued{
  public :
   string book_title;
   string book_isbn;
   string book_aut;
   string book_pub;
   string user_id;
   string user_name;
   int issue_date;
};

//
vector <Book_issued> b;

class User{
 public : 
    string Name;
    string ID;
    string Password;
    int code;
  
};

class Student : public User {
 public : 
    int Fine_amount ;

    int Calculate_Fine(void){
       int fine = 0;
       cout<<endl<<endl<<"Enter return date : "; int dt; cin>>dt;
       cout<<endl<<endl<<"Enter your ID: "; string id; cin>>id;

       for(int i=0;i<b.size();i++){
        if(b[i].user_id == id){
            int z = 0;
            z = dt - b[i].issue_date;
            if( z >= 30){
              z = z-30;
              fine = fine + 2*z; } 
          }
       }
       
       this->Fine_amount = fine;
       return fine;
   };

    void Clear_fine_amount(void){
      cout<<endl<<endl<<"Fine deposited!"<<endl;
      Fine_amount = 0;
  };

};

class Professor : public User {
 public : 
    int Fine_amount ;

    int Calculate_Fine(void){

      int fine = 0;
       cout<<endl<<endl<<"Enter return's date : "; int dt; cin>>dt;
       cout<<endl<<endl<<"Enter your ID: "; string id; cin>>id;

       for(int i=0;i<b.size();i++){
        if(b[i].user_id == id){
            int z = 0;
            z = dt - b[i].issue_date;
            if( z >= 60){
              z = z-60;
              fine = fine + 5*z; } 
          }
       }
      this->Fine_amount = fine;
      return fine;
      
  };

    void Clear_fine_amount(void){
      cout<<endl<<endl<<"Fine deposited!"<<endl;
     Fine_amount = 0;
  };
  
};

class Librarian : public User {

};



// Global declarations for the system
vector <User> v;
vector <Book> u;
vector <Student> s;
vector <Professor> p;

class User_Database{
    public :

      void Add_User (){
        cout<<endl;
        cout<<"****No spaces are allowed in the string!****"<<endl<<endl;
       
        cout<<"Enter the Name : "; string nm ; cin>>nm;
        cout<<"Enter the ID : "; string id; cin>>id;
        cout<<"Enter the password : "; string pw; cin>>pw;
        cout<<endl<<endl;
        cout<<"2. Student "<<endl;
        cout<<"3. Professor"<<endl;
        cout<<"Enter type of User to be added : "; int x; cin>>x;
    
        int found = 0;

        for (int i=0;i<v.size();i++){
          if( v[i].ID == id ) 
          { found = 1; break; } 

          }

          if(found == 1){
            cout<<endl<<"USER WITH SAME ID ALREADY EXISTS"<<endl;
            return ;
          } 

          else {
            if(x == 2 || x == 3){
             User U;
             U.Name = nm ; U.ID = id; U.Password = pw; U.code =x;
             v.push_back(U);
             
             if(x==2){
               Student S;
               S.Name = nm ; S.ID = id; S.Password = pw; S.code =x;
               S.Fine_amount = 0;
               s.push_back(S);
                }
             else if (x==3){
               Professor P;
               P.Name = nm ; P.ID = id; P.Password = pw; P.code =x;
               P.Fine_amount = 0;
               p.push_back(P);
             }   
            }
            else { cout<<endl<<endl<<"Invalid choice entered!"<<endl<<endl;
            return ;

            }
          }
          cout<<endl<<"USER ADDED SUCCESSFULLY"<<endl;
          return ;
      
      };  

      void Update_User(){

       cout<<endl<<endl;
       cout<<"***No spaces are allowed in the string!****"<<endl<<endl;
       cout<<"Enter the ID: "; string id; cin>>id;
       int found = 0; int index = -1;

       for (int i=0; i<v.size(); i++){
        if( v[i].ID == id ){
          found = 1;
          index = i;
          break;}
         }
       if(found == 1){
        cout<<endl<<endl;
        cout<<"****No spaces are allowed in the string!****"<<endl<<endl;
        cout<<"Enter the new name : "; string nm; cin>>nm;
        cout<<"Enter the new ID : "; string id; cin>>id;
        cout<<"Enter the new password : "; string pw; cin>>pw;
        
       v[index].Name = nm; v[index].ID = id; v[index].Password = pw;
       cout<<endl<<"USER UPDATED SUCCESSFULLY"<<endl;
       }
       else{
       cout<<endl<<"USER WITH THIS ID NOT FOUND"<<endl;}
       return ; 

      };

      void Delete_User(){

       cout<<endl<<endl;
       cout<<"***No spaces are allowed in the string!****"<<endl<<endl;
       cout<<"Enter the ID : "; string id; cin>>id;

       int found = 0;
        for(int i=0; i<v.size(); i++){
          if( v[i].ID == id ){ 
            found = 1;
            v.erase(v.begin() + i);
            cout<<endl<<"USER DELETED SUCCESSFULLY"<<endl;
            } 
        }
        if (found == 0){
        cout<<endl<<"USER WITH THIS ID NOT FOUND"<<endl;}
        return ;
      };


       void Search_User(){

       cout<<endl<<endl;
       cout<<"***No spaces are allowed in the string!****"<<endl<<endl;
       cout<<"Enter the ID: "; string id; cin>>id;
       int found = 0; 

       for (int i=0; i<v.size(); i++){
        if( v[i].ID == id ){
          found++;
          cout<<"-----------------------------------"<<endl;
          cout<<"Name of the User: "<<v[i].Name<<endl;
          cout<<"User ID: "<<v[i].ID<<endl;;
          }
         }     

         if(found == 0){
           cout<<endl<<"USER WITH THIS ID NOT FOUND"<<endl;
         }
         
         return ;
      };

};



class Book_Database{
  
  public :
    void Add_Book  () {
      cout<<endl<<endl;
      cout<<"***No spaces are allowed in the string!****"<<endl<<endl;
      cout<<"Enter the Title : "; string tit; cin>>tit;
      cout<<"Enter the Authtor : "; string aut; cin>>aut;
      cout<<"Enter the ISBN : "; string isb; cin>>isb;
      cout<<"Enter the publication :"; string pub; cin>>pub;
      
      Book B;
      B.Title = tit; B.Author = aut; B.ISBN = isb ; B.publication = pub;
      u.push_back(B);

      Book_issued B1;
      B1.book_title = tit; B1.book_isbn = isb; B1.user_id = "\0"; B1.issue_date = -1;
      B1.book_pub = pub; B1.book_aut = aut; B1.user_name = "\0";
      b.push_back(B1);
       
      cout<<endl<<"BOOK ADDED SUCCESSFULLY"<<endl;
      return ; 
  
    };

    void Delete_Book(){
      cout<<endl<<endl;
      cout<<"***No spaces are allowed in the string!****"<<endl<<endl;
      cout<<"Enter the Title: "; string tit; cin>>tit;
      cout<<"Enter the ISBN: " ; string isb; cin>>isb;

      int found = 0;
      for (int i=0; i<u.size(); i++){
        if( u[i].Title == tit && u[i].ISBN == isb) 
        { found = 1;
          u.erase(u.begin() + i);
          cout<<endl<<"BOOK DELETED SUCCESSFULLY"<<endl;
           } 
        }
        if(found == 0){
         cout<<endl<<"BOOK NOT FOUND"<<endl; }
         return ;
      };

     void Update_Book(){
       cout<<endl<<endl;
       cout<<"***No spaces are allowed in the string!****"<<endl<<endl;
       cout<<"Enter the Title: "; string tit; cin>>tit;
       cout<<"Enter the ISBN : "; string isb; cin>>isb;
       
       int found = 0;

       for(int i=0; i<u.size(); i++){
         if(u[i].Title == tit && u[i].ISBN == isb){
           found = 1;

           cout<<endl<<endl;
           cout<<"Enter the new title: "; string tit; cin>>tit;
           cout<<"Enter the new author : "; string aut1; cin>>aut1;
           cout<<"Enter the new publication: "; string pub; cin>>pub;
           cout<<"Enter the new ISBN : "; string isb1; cin>>isb1;

           u[i].Title = tit; u[i].ISBN =isb1; 
           u[i].Author =aut1; u[i].publication =pub;
           cout<<endl<<"BOOK UPDATED SUCCESSFULLY"<<endl;
         }
       }
       if(found == 0 ){
       cout<<endl<<"BOOK NOT FOUND"<<endl; }
       return ;
     };

     void Search_Book(){
       cout<<endl<<endl;
       cout<<"***No spaces are allowed in the string!****"<<endl<<endl;
       cout<<"Enter the Title: "; string tit; cin>>tit;

       int found = 0;
       for (int i=0; i<u.size(); i++){
        if( u[i].Title == tit ) 
          { found++;
            cout<<"------------------------------"<<endl;
            cout<<"Title: "<<u[i].Title<<endl;
            cout<<"ISBN: "<<u[i].ISBN<<endl;
            cout<<"Author: "<<u[i].Author<<endl;
            cout<<"Publication: "<<u[i].publication<<endl;
           } 
        }
        
         if (found == 0) {
         cout<<endl<<"BOOK NOT FOUND"<<endl;}
         return;
     };  
  
  };

 // 
 User_Database u_db;
 Book_Database b_db;
 

 void issue_book( int x){
   cout<<endl<<endl;
   cout<<"***No spaces are allowed in the string!****"<<endl<<endl;
   cout<<"Enter your ID:  "; string id; cin>>id;
   cout<<"Enter your Name: "; string nm; cin>>nm;
   
   int f = 0;
   for(int l=0 ;l<v.size();l++){
     if(v[l].ID == id){
       f++;
     }
   }
   if(f==0){
     cout<<endl<<"User not found"<<endl;
     return;}

   int found = 0; 

   for(int i=0;i<b.size();i++){     // finding number of books issued to this user.
       if(b[i].user_id == id){
          found++;
        }
      }     

    if(x == 2){

      if( found >= 5){
         cout<<endl<<endl<<"You cannot be issued more than 5 books"<<endl<<endl;
        }

      else{
         cout<<endl<<endl;
         cout<<"Enter the book title: "; string tit; cin>>tit;
         cout<<"Enter the author: "; string aut;cin>>aut;
         cout<<"Enter issue date: "; int dt; cin>>dt;
          
         int l = 0,ind = -1;
         for(int i=0;i<b.size();i++){
         if( b[i].book_title == tit && b[i].book_aut == aut && b[i].user_id == "\0"){
            l=1;
            ind = i;
            break;}
           }
           if(l == 1){
             b[ind].user_id = id; b[ind].user_name = nm; b[ind].issue_date = dt;
             cout<<endl<<endl<<"Book issued for 30 days"<<endl;
           }
           
           else{
             int f=0;
             for(int i=0;i<u.size();i++){
               if(u[i].Title == tit && u[i].Author == aut){
                 f++;
               }
               if(f==0){
                 cout<<endl<<endl<<"Book not found!"<<endl;
               }
               else{
                 cout<<endl<<endl<<"Book already issued to some other user"<<endl;
               }
             }
           }

        }
      }

      else{
        cout<<endl<<endl;
        cout<<"Enter the book title: "; string tit; cin>>tit;
        cout<<"Enter the author: "; string aut;cin>>aut;
        cout<<"Enter issue date: "; int dt; cin>>dt;
        int l = 0,ind = -1;
        for(int i=0;i<b.size();i++){
           if( b[i].book_title == tit && b[i].book_aut == aut && b[i].user_id == "\0"){
           l=1;
           ind = i;
           break;}
          }
        if(l == 1){
           b[ind].user_id = id; b[ind].user_name = nm; b[ind].issue_date=dt;
           cout<<endl<<endl<<"Book issued for 60 days"<<endl<<endl;
          }
          else{
            int f=0;
             for(int i=0;i<u.size();i++){
               if(u[i].Title == tit && u[i].Author == aut){
                 f++;
               }
               if(f==0){
                 cout<<endl<<endl<<"Book not found!"<<endl;
               }
               else{
                 cout<<endl<<endl<<"Book already issued to some other user"<<endl;
               }
             }
          }
       }
 }

 
 
 void List_of_your_books(){
    cout<<endl<<endl;
    cout<<"***No spaces are allowed in the string!****"<<endl<<endl;
    cout<<"Enter your ID: "; string id; cin>>id;
    int found = 0;
    for(int i=0;i<b.size();i++){
        if(b[i].user_id == id){
            cout<<"BOOK"<<i+1<<endl;
            cout<<"Title : "<<b[i].book_title<<endl;
            cout<<"ISBN  : "<<b[i].book_isbn<<endl;
            cout<<"Issue date : "<<b[i].issue_date<<endl;
            cout<<"______________________________________________"<<endl;
            found++;
        }
    }

    if(found == 0){
        cout<<endl<<"NO BOOKS ISSUED TO THIS USER!"<<endl;
    }
    return;

}

void Which_books(){

    cout<<endl<<endl;
    cout<<"***No spaces are allowed in the string!****"<<endl<<endl;
    cout<<"Enter the USER ID: "; string id; cin>>id;
    
    int found = 0;

    for(int i=0;i<b.size();i++){
        if( b[i].user_id == id ){
          found++ ;
          cout<<endl<<"BOOK"<<i+1<<": "<<endl;
          cout<<"Title : "<<b[i].book_title<<endl;
          cout<<"Author : "<<b[i].book_aut<<endl;
        }

  }    

  if(found == 0){
      cout<<endl<<"NO BOOKS ISSUED TO THIS USER!"<<endl;
  }
  return ;
}

void Which_User(){
  cout<<endl<<endl;
  cout<<"***No spaces are allowed in the string!****"<<endl<<endl;
  cout<<"Enter the title of book : "; string tit; cin>>tit;
  cout<<"Enter ISBN : "; string isb; cin>>isb;

  int found = 0;

  for(int i=0;i<b.size();i++) {
    if( b[i].book_title == tit && b[i].book_isbn == isb){
        if(b[i].user_id == "\0"){
            cout<<endl<<"NOT issued to any user"<<endl;
        }
        else{
            cout<<endl<<"ISSUED TO - ";
            cout<<endl<<"User ID : "<<b[i].user_id;
            cout<<endl<<"User Name : "<<b[i].user_name;
            cout<<endl<<"Issue_date "<<b[i].issue_date;
        }
      found = 1;
    }

  }
  
   if(found == 0){
        cout<<endl<<"Book NOT found!"<<endl;
    }
    return;
}

void Availability_of_book(){
  cout<<endl<<endl;
  cout<<"***No spaces are allowed in the string!****"<<endl<<endl;
  cout<<"Enter the title of book : "; string tit; cin>>tit;
  cout<<"Enter the author name: "; string aut; cin>>aut;

  int found = 0;
  for(int i=0;i<b.size();i++){
    if( b[i].book_title == tit && b[i].book_aut == aut && b[i].user_id == "\0"){
      found = 1;
      cout<<endl<<"Available"<<endl;
      break;
    }
  }

  if(found == 0){
    int f=0;
    for(int i=0;i<u.size();i++){
      if(u[i].Title == tit && u[i].Author == aut){
        f++;
        }
      if(f==0){
        cout<<endl<<endl<<"Book not found!"<<endl;
        }
      else{
        cout<<endl<<endl<<"Book already issued to some other user"<<endl;
       }
     }
   }
  return ;
 } 

 void List_of_users(){
   if(v.size()==0){
    cout<<endl<<endl<<"No users in the database!"<<endl<<endl;
   }

  cout<<"-------------------- LIST OF USERS ------------------"<<endl;

  for(int i=0; i<v.size(); i++)
  {
    cout<<"Name     : "<<v[i].Name<<endl;
    cout<<"ID       : "<<v[i].ID<<endl;
    cout<<"Password : "<<v[i].Password<<endl;
    cout<<"____________________________________________________"<<endl;
  }
 }

 void List_of_Books(){// This is a one time system.
  // Once we exit, whole database is gone.
  // Only librarian can start the function for the first time and

   if(u.size() == 0){
     cout<<endl<<endl<<"NO BOOKS IN THE DATABASE"<<endl<<endl;
     return;
   }
  cout<<"-------------------LIST OF BOOKS-----------------------"<<endl;
    
  for(int i=0; i<u.size(); i++){
    cout<<"Title       : "<<u[i].Title<<endl;
    cout<<"Author      : "<<u[i].Author<<endl;
    cout<<"ISBN        : "<<u[i].ISBN<<endl;
    cout<<"Publication : "<<u[i].publication<<endl;
    cout<<"____________________________________________________"<<endl;
  }
}



// TABS


void Home();
void Login();
void verification();


void Librarian_Home(){

  cout<<endl<<endl;

  cout<<"1. Add User"<<endl<<"2. Update User"<<endl<<"3. Delete User"<<endl;

  cout<<"4. Add Book"<<endl<<"5. Update Book"<<endl<<"6. Delete Book"<<endl;
  
  cout<<"7. List all users"<<endl<<"8. List all books"<<endl;
  cout<<"9. Check which user has been issued a book"<<endl<<"10. Check list of books issued to a user"<<endl;
  
  cout<<"11. Logout"<<endl;

  cout<<endl<<endl<<"Enter Your choice : ";
  int x;
  cin>>x;
  
  switch (x)
  {
  case 1 :
    u_db.Add_User();
    Librarian_Home();
    break;
  case 2 :
    u_db.Update_User();
    Librarian_Home();
    break;
  case 3 :
    u_db.Delete_User();
    Librarian_Home();
    break;
  case 4:
    b_db.Add_Book();
    Librarian_Home();
    break;
  case 5 :
    b_db.Update_Book();
    Librarian_Home();
    break;
  case 6:
    b_db.Delete_Book();
    Librarian_Home();
    break;
  case 7 :
    List_of_users();
    cout<<endl<<endl;
    Librarian_Home();
    break;
  case 8 :
    List_of_Books();
    cout<<endl<<endl;
    Librarian_Home();
    break;
  case 9 :
    Which_User();
    cout<<endl<<endl;
    Librarian_Home();
    break;
  case 10 :
    Which_books();
    cout<<endl<<endl;
    Librarian_Home();
    break;
  case 11 :
    Login();
    break;    
  default:
   cout<<"***Invalid choice entered!***"<<endl<<endl;
   Librarian_Home();
    break;

  }
  
}

void Professor_Home(string s){
  cout<<endl;
  cout<<"1. Issue a book"<<endl;
  cout<<"2. List of all books"<<endl;
  cout<<"3. Check list of your books"<<endl;
  cout<<"4. Check availability of books"<<endl; 
  cout<<"5. Calculate fine amount"<<endl;
  cout<<"6. Clear fine amount"<<endl;
  cout<<"7. Logout";
  
  cout<<endl<<endl<<"Enter your choice : ";
  int n; cin>>n;
  int ind = -1;
  for(int i=0;i<p.size();i++){
    if(p[i].ID == s){
           ind = i;}
    }
  
  switch (n)
  {
  case 2: 
    List_of_Books();
    Professor_Home(s);
    break;
  case 3:
    List_of_your_books();
    Professor_Home(s);
    break;
  case 4:
    Availability_of_book();  
    Professor_Home(s);
    break;
  case 1:
    issue_book(3);
    Professor_Home(s);
    break;
  case 5:
    int fine;
    fine = p[ind].Calculate_Fine();
    p[ind].Fine_amount = fine;
    cout<<endl<<endl<<"Fine amount: "<<fine<<endl;
    Professor_Home(s);
    break;
  case 6:
    p[ind].Fine_amount = 0;
    Professor_Home(s);
    break;
  case 7:   
    Login();
    break;
  default:
    cout<<endl<<"Invalid choice entered!"<<endl<<endl;
    Professor_Home(s);
    break;
  }
}

void Student_Home(string k){
  cout<<endl;
  cout<<"1. Issue a book"<<endl;
  cout<<"2. List of all books"<<endl;
  cout<<"3. Check list of your books"<<endl;
  cout<<"4. Check availability of books"<<endl; 
  cout<<"5. Calculate fine amount"<<endl;
  cout<<"6. Clear fine amount"<<endl;
  cout<<"7. Logout"<<endl;
  
  cout<<endl<<endl<<"Enter your choice : ";
  int n; cin>>n;
  int ind = -1;
  for(int i=0;i<s.size();i++){
    if(s[i].ID == k){
           ind = i;}
    }

  switch (n)
  {
  case 1: 
    issue_book(2);
    Student_Home(k);
    break;
  case 2:
    List_of_Books();
    Student_Home(k);
    break;
  case 3:
    List_of_your_books();
    Student_Home(k);
    break;
  case 4:
    Availability_of_book();
    Student_Home(k);
    break;    
  case 5:
    int fine;
    fine = s[ind].Calculate_Fine();
    s[ind].Fine_amount = fine;
    cout<<endl<<endl<<"Fine amount: "<<fine<<endl;
    Student_Home(k);
    break;
  case 6: \
     s[ind].Fine_amount=0;
     Student_Home(k);
     break;
  case 7:
   Login();
   break; 
  default:
    cout<<endl<<"Invalid choice entered!"<<endl<<endl;
    Student_Home(k);
    break;
  }
}

void Verification (int x){

  cout<<endl<<endl;
  cout<<"***No spaces are allowed in the string!****"<<endl<<endl;
  cout<<"Enter the Username : "; string us; cin>>us;
  cout<<"Enter the password : " ; string pw; cin>>pw;
  
  int found = 0;
  for(int i =0;i<v.size();i++){
    if(v[i].ID == us && v[i].Password == pw){
      found = 1;
      break;
    }
  }

  if(found == 0){
    cout<<endl<<"Incorrect username or password!"<<endl;
    cout<<"1. Login Page"<<endl;
    cout<<"2. Try Again"<<endl;
    cout<<"Enter your choice number : ";

    int l; cin>>l;

  if( l==1){
      Login();}

    else {
      Verification(x);
    } 
  }
  
  cout<<endl<<"You have Logged in successfully"<<endl;
  
   if(x==1){
    Librarian_Home();
  }
   else if( x ==2 ){
    Student_Home(us);
  }
    else {
    Professor_Home(us);
  }

  return;
} 

void Home (void)
{
  cout<<"1. Librarian"<<endl;
  cout<<"2. Student"<<endl;
  cout<<"3. Professor"<<endl;
  cout<<"Enter your code : ";

  int n; cin>>n;
  if( n==1 || n==2 || n==3){
    Verification(n);
  }
  else{
    cout<<endl<<"Invalid Choice"<<endl<<endl;
    Login();
  }
  return;
}

void Login(void){
  cout<<endl<<endl;
  cout<<"   |||||       LIBRARY MANAGEMENT SYSTEM      |||||     "<<endl<<endl;
  cout<<"Enter 1 to Login"<<endl;
  cout<<"Enter 2 to Exit"<<endl;
  cout<<"Enter here : ";
  int n;
  cin >> n;
  if(n==1){
   Home();
   }
  else if( n== 2) {
      cout<<endl<<endl<<"Only librarian can exit the system!"<<endl<<endl;
      cout<<"Enter the Username : "; string us; cin>>us;
      cout<<"Enter the password : " ; string pw; cin>>pw;
      
      if( us == v[0].ID && pw == v[0].Password ){
      exit(0);}
      else{
          cout<<endl<<"Wrong credentials"<<endl;
          Login();
      }
    }

  else {
    cout<<endl<<"Invalid Choice"<<endl<<endl;
    Login();
  }
  return;
}


 int main(){ 
  
  User librarian_1;
  librarian_1.ID = "admin";
  librarian_1.Name = "ADMIN";
  librarian_1.Password = "admin";
  librarian_1.code = 1;
  
  v.push_back(librarian_1);

  Login();
  
}
