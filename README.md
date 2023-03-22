# group_x

Projektin aihe on yksinkertainen opiskelijarekisteri (vrt. Peppi)

## Ui suunnitelma

Sovelluksen käyttöliittymä on seuraavanlainen
<img src="ui_kuva.png">

## ER-kaavio

Hahmotelma <br>
<img src="er_plan.png">
<br>
Lopullinen<br>
<img src="er_diagram_v2.png">

### Oikeudet tietokantaan

<pre>
create user netuser@127.0.0.1 identified by 'netpass';
grant all on peppidb.* to netuser@127.0.0.1;
</pre>

## .env

Huom! Tiedosto .env pitäisi oikeasti jättää pois GitReposta (ainakin julkisesta ja varsinkin jos siinä on salasanoja)

Tämän sovellusen **.env** on seuraavanlainen
<pre>
SQL_SERVER='mysql://netuser:netpass@127.0.0.1/peppidb'
PORT=3000
MY_TOKEN=e8IP8RwsnugR0Wt22K2YX9P8jDyPj/zVocZiIb97nOebNnhEv5fS4c5C2OzUFxBcuGgWY2HTF+u5lzTQUCRt7A==
</pre>