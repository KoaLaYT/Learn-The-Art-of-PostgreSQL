-- name: genre-top-n
-- Get the N top tracks by genre

SELECT g."Name" AS genre,
       CASE WHEN LENGTH(ss.name) > 15
            THEN SUBSTRING(ss.name FROM 1 FOR 15) || '...'
            ELSE ss.name
       END AS track,
       a."Name" AS artist
FROM          "Genre" g
    LEFT JOIN LATERAL
    (
        SELECT t."Name", t."AlbumId", COUNT(pt."PlaylistId")
        FROM          "Track" t
            LEFT JOIN "PlaylistTrack" pt USING("TrackId")
        WHERE t."GenreId" = g."GenreId"
        GROUP BY t."TrackId"
        ORDER BY count DESC
        LIMIT $1
    )
         ss(name, albumid, count) ON TRUE
    JOIN "Album" al ON ss.albumid = al."AlbumId"
    JOIN "Artist" a USING("ArtistId")
ORDER BY g."Name", ss.count DESC;