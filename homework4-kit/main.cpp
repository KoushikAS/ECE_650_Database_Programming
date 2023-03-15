#include <fstream>
#include <iostream>
#include <pqxx/pqxx>
#include <sstream>
#include <string>

#include "exerciser.h"
#include "query_funcs.h"

using namespace std;
using namespace pqxx;

void readState(connection * C) {
  fstream state_file;
  state_file.open("state.txt", ios::in);
  if (state_file.is_open()) {
    string line, word;
    while (getline(state_file, line)) {
      stringstream s(line);
      getline(s, word, ' ');
      int id = stoi(word);
      getline(s, word, ' ');
      string name = word;

      add_state(C, name);
    }
    state_file.close();
  }
}

void readColor(connection * C) {
  fstream color_file;
  color_file.open("color.txt", ios::in);
  if (color_file.is_open()) {
    string line, word;
    while (getline(color_file, line)) {
      stringstream s(line);
      getline(s, word, ' ');
      int id = stoi(word);
      getline(s, word, ' ');
      string name = word;

      add_color(C, name);
    }
    color_file.close();
  }
}

int main(int argc, char * argv[]) {
  //Allocate & initialize a Postgres connection object
  connection * C;

  try {
    //Establish a connection to the database
    //Parameters: database name, user name, user password
    C = new connection("dbname=ACC_BBALL user=postgres password=passw0rd");
    if (C->is_open()) {
      cout << "Opened database successfully: " << C->dbname() << endl;
    }
    else {
      cout << "Can't open database" << endl;
      return 1;
    }
  }
  catch (const std::exception & e) {
    cerr << e.what() << std::endl;
    return 1;
  }

  initalize_db(C);
  readState(C);
  readColor(C);
  //TODO: create PLAYER, TEAM, STATE, and COLOR tables in the ACC_BBALL database
  //      load each table with rows from the provided source txt files

  exercise(C);

  //Close database connection
  C->disconnect();

  return 0;
}
