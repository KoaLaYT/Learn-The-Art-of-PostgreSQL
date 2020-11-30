#include <fmt/core.h>

#include <database.hpp>
#include <string>

using namespace std;

void sql_artist(Database& db, int num)
{
    auto result = db.exec_prepared("artist", num);

    const string format = "{:>15} {}\n";
    fmt::print(format, "Artist", "Count");
    for (auto row : result) {
        fmt::print(format, row[0].as<string>(), row[1].as<int>());
    }
}

void sql_album(Database& db, string&& artist)
{
    auto result = db.exec_prepared("album", forward<string>(artist));

    const string format = "{:>40} {}\n";
    fmt::print(format, "Album", "Duration");
    for (auto row : result) {
        fmt::print(format, row[0].as<string>(), row[1].as<string>());
    }
}

void sql_genre_topn(Database& db, int num)
{
    auto result = db.exec_prepared("genre-topn", num);
    const string format = "{:20} | {:18} | {:50}\n";
    fmt::print(format, "Genre", "Track", "Artist");
    fmt::print("{:-^20}-+-{:-^18}-+-{:-^50}\n", "", "", "");
    for (auto row : result) {
        fmt::print(format,
                   row[0].as<string>(),
                   row[1].as<string>(),
                   row[2].as<string>());
    }
}

int main()
{
    Database db{CHINOOKDB_CONN_STR, BASE_DIR + "/chinook/sql"};

    // sql_artist(db, 10);
    // sql_album(db, "Faith No More");
    sql_genre_topn(db, 1);

    return 0;
}