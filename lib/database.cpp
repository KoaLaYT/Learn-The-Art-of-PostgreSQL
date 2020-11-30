#include "../include/database.hpp"

const string CHINOOKDB_CONN_STR = "user=chinook dbname=chinook password=chinook";
const string F1DB_CONN_STR = "user=f1db dbname=f1db password=f1db";
const string BASE_DIR = "/Users/koalayt/Study/Learning-PostgreSQL/The-Art-Of-PostgreSQL";

namespace sql {

string from_file(const string& filename)
{
    ifstream ifs{filename};
    if (!ifs.is_open()) {
        fmt::print("can't open file: {}?\n", filename);
        exit(1);
    }
    string sql;
    getline(ifs, sql, (char)ifs.eof());
    return sql;
}

};  // namespace sql

pqxx::result Database::exec_sql(const string& file)
{
    pqxx::work w{c};
    pqxx::result r{w.exec(sql::from_file(file))};
    w.commit();
    return r;
}

void Database::prepare_sql(const string& search_path)
{
    for (auto& p : filesystem::recursive_directory_iterator{search_path}) {
        auto path = p.path();
        if (path.extension() == ".sql") {
            c.prepare(path.stem(), sql::from_file(path));
        }
    }
}