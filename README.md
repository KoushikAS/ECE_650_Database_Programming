# Project #4: Database Programming - Implementation Overview
ECE 650 – Spring 2022

## Project Description
This project involved the creation of a PostgreSQL database named `ACC_BBALL`, tailored to store and manage data related to ACC basketball teams. It was developed and tested on a Linux Virtual Machine using Ubuntu 20.04. The main goal was to facilitate complex queries about player statistics and team attributes through a well-structured database.

## Key Features
- **Database Creation**: Implemented in C++ to set up and initialize tables in the `ACC_BBALL` database.
- **Data Ingestion**: Developed a routine to read data from provided text files (`player.txt`, `team.txt`, `state.txt`, `color.txt`) and populate the database tables.
- **Query Interface**: Created a C++ library offering functions to interact with the database, enabling the addition of new data and fetching specific information.
- **User Authentication**: Configured database access for the user `postgres` with a predefined password.

## Database Schema
The database comprises four primary tables:
- `PLAYER`: Contains player-specific details and game statistics.
- `TEAM`: Stores information about different basketball teams.
- `STATE`: Lists U.S. states with corresponding IDs.
- `COLOR`: Details of color IDs and their respective names.

## Implementation Details
### Main Components
- `main.cpp`: Manages database setup, table creation, and data insertion.
- `query_funcs.cpp` and `query_funcs.h`: Functions for database queries and data manipulation.
- `exerciser.cpp` and `exerciser.h`: Used for testing and demonstrating database queries.

### Setup and Configuration
- PostgreSQL installation along with the `libpqxx-dev` package for C++ integration.
- Use of `sudo apt-get install` commands for environment setup.

### Testing and Validation
- Implementation of `diff -w output.txt validation.txt` for output comparison and validation.
- Ensured SQL output headers matched the table attribute definitions as per project specifications.

## Reflections and Learning Outcomes
- Gained hands-on experience in setting up and managing a PostgreSQL database.
- Learned the intricacies of database programming and data handling in C++.
- Understood the importance of precise query functions in database interaction.

## Contributions

This project was completed as part of an academic assignment with requirments provided requirments.pdf. Contributions were made solely by Koushik Annareddy Sreenath, adhering to the project guidelines and requirements set by the course ECE-650 Systems Program & Engineering

## License

This project is an academic assignment and is subject to university guidelines on academic integrity and software use.

## Acknowledgments

- Thanks to Rabih Younes and the course staff for providing guidance and support throughout the project.
