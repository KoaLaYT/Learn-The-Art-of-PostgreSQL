-- name: list-albums-by-artist
-- List the album titles and duration of a given artist

SELECT a."Title" as album,
       SUM(t."Milliseconds") * interval '1 ms' as duration
FROM          "Album" a
         JOIN "Artist" ar using("ArtistId")
    LEFT JOIN "Track" t using("AlbumId") 
WHERE ar."Name" = $1
GROUP BY album
ORDER BY album