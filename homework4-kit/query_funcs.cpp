#include "query_funcs.h"

#include <pqxx/pqxx>

void initalize_db(connection * C) {
  char * sql =
      "DROP TABLE IF EXISTS COLOR, STATE, TEAM, PLAYER;"
      "CREATE TABLE COLOR(COLOR_ID SERIAL NOT NULL, NAME TEXT "
      "NOT NULL, PRIMARY KEY(COLOR_ID));"
      "CREATE TABLE STATE(STATE_ID SERIAL NOT NULL, NAME TEXT "
      "NOT NULL, PRIMARY KEY(STATE_ID));"
      "CREATE TABLE TEAM(TEAM_ID INT PRIMARY KEY NOT NULL, NAME TEXT NOT NULL, STATE_ID "
      "INT NOT NULL, COLOR_ID INT NOT NULL, WINS INT, LOOSES INT, CONSTRAINT "
      "FK_STATE_TEAM FOREIGN "
      "KEY(STATE_ID) REFERENCES STATE(STATE_ID) ON DELETE CASCADE,  CONSTRAINT "
      "FK_COLOR_TEAM FOREIGN "
      "KEY(COLOR_ID) REFERENCES COLOR(COLOR_ID) ON DELETE CASCADE);"
      "CREATE TABLE PLAYER(PLAYER_ID INT PRIMARY KEY NOT NULL, TEAM_ID INT NOT NULL, "
      "UNIFORM_NUM INT, FIRST_NAME TEXT, LAST_NAME TEXT, MPG INT, PPG INT, RPG INT, ARG "
      "INT, SPG INT, BPG INT, CONSTRAINT FK_TEAM_PLAYER FOREIGN "
      "KEY(TEAM_ID) REFERENCES TEAM(TEAM_ID) ON DELETE CASCADE);";

  work W(*C);
  W.exec(sql);
  W.commit();
}

void add_player(connection * C,
                int team_id,
                int jersey_num,
                string first_name,
                string last_name,
                int mpg,
                int ppg,
                int rpg,
                int apg,
                double spg,
                double bpg) {
}

void add_team(connection * C,
              string name,
              int state_id,
              int color_id,
              int wins,
              int losses) {
}

void add_state(connection * C, string name) {
  work W(*C);
  C->prepare("insert_state", "INSERT INTO STATE (NAME) VALUES ($1)");
  W.prepared("insert_state")(name).exec();
  W.commit();
}

void add_color(connection * C, string name) {
  work W(*C);
  C->prepare("insert_color", "INSERT INTO COLOR (NAME) VALUES ($1)");
  W.prepared("insert_color")(name).exec();
  W.commit();
}

/*
 * All use_ params are used as flags for corresponding attributes
 * a 1 for a use_ param means this attribute is enabled (i.e. a WHERE clause is needed)
 * a 0 for a use_ param means this attribute is disabled
 */
void query1(connection * C,
            int use_mpg,
            int min_mpg,
            int max_mpg,
            int use_ppg,
            int min_ppg,
            int max_ppg,
            int use_rpg,
            int min_rpg,
            int max_rpg,
            int use_apg,
            int min_apg,
            int max_apg,
            int use_spg,
            double min_spg,
            double max_spg,
            int use_bpg,
            double min_bpg,
            double max_bpg) {
}

void query2(connection * C, string team_color) {
}

void query3(connection * C, string team_name) {
}

void query4(connection * C, string team_state, string team_color) {
}

void query5(connection * C, int num_wins) {
}
