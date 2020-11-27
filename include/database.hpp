#ifndef DATABASE_HPP_20201127
#define DATABASE_HPP_20201127

#include <fmt/core.h>

#include <filesystem>
#include <fstream>
#include <pqxx/pqxx>
#include <string>

using namespace std;

extern const string DB_CONN_STR;
extern const string BASE_DIR;

class Database {
public:
    explicit Database(
        const string& connect_str,
        const string& search_path) : c{connect_str}
    {
        prepare_sql(search_path);
    }

    /**
     * @brief exec sql from file
     * 
     * @param file the sql file
     * @return pqxx::result 
     */
    pqxx::result exec_sql(const string& file);

    /**
     * @brief exec prepared sql with args
     * 
     * @tparam Args 
     * @param sql the prepared sql statement
     * @param args the sql required arguments
     * @return pqxx::result 
     */
    template <typename... Args>
    pqxx::result exec_prepared(const string& sql, Args&&... args)
    {
        pqxx::work w{c};
        pqxx::result r{w.exec_prepared(sql, forward<Args>(args)...)};
        w.commit();
        return r;
    }

private:
    pqxx::connection c;
    void prepare_sql(const string& search_path);
};

#endif