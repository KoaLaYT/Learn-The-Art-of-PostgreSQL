-- name: top-artists-by-album
-- Get the list of the N artists with the most albums
   
SELECT a."Name", count(*) as albums
FROM "Artist" a
left join "Album" using("ArtistId") 
group by a."Name"
order by albums desc
limit $1;