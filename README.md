# Videobase
Project work for academic studies
Hungarian description of the solved problem:
Készítsünk programot, amellyel egy videotéka nyilvántartását valósíthatjuk meg
az alábbi **funkciókkal**:

- [ ] A programban listázhatóak a filmek adatai (cím, főszereplők, rendező,
forgalmazó, megjelenés éve), és látható, hogy kölcsönözve vannak-e, vagy
sem. Amennyiben egy film bent van, akkor zárolható (és a zárolás
visszaállítható), ekkor nem kölcsönözhető. A lista szűkíthető a kikölcsözhető,
illetve a kikölcsönzött filmekre.
- [ ] Lehetőségünk van új filmet felvenni, módosítani, illetve törölni (amennyiben
nincs kikölcsönözve).
- [ ] Film kölcsönzéséhez válasszuk ki a tagot, illetve a filmet. Csak akkor lehet
kölcsönözni, ha bent van a film, és nem zárolt. A kölcsönzés dátumát
automatikusan rögzítsük.
- [ ] A kikölcsönzött filmeket lehessen visszahozni. A visszahozatal dátumát
automatikusan rögzítsük. Mivel a kölcsönzés ideje 24 óra, jelezzük, ha a tag
késett (írjuk ki a késés idejét napban, illetve órában), és ezért pótdíjat kell
fizetnie.


Az adatbázis az alábbi adatokat tárolja:
- tagok (név, cím, telefonszám);
- filmek (cím, főszereplők, rendező, forgalmazó, megjelenés éve, zárolt-e)
- kölcsönzések (tag, film, kölcsönzés ideje, visszahozatal ideje).
