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
<img src="er_diagram.png">

### Oikeudet tietokantaan

<pre>
create user netuser@127.0.0.1 identified by 'netpass';
grant all on peppidb.* to netuser@127.0.0.1;
</pre>