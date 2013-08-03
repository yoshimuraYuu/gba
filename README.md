-------
組み込みOS実験 課題2
-------

201111411
吉村　優

--------------
何をするプログラムか
--------------

ブロック崩しを行うプログラム。

--------------
プログラムの使い方
--------------

まず、プログラムを読み込むと"Press START"と表示されスタート待ちの状態になる。
この状態から

1. `START`ボタンを押す
2. `START` + `SELECT`ボタンを押す

ことでゲームが開始される。
このどちらで開始してもラケットの使い方は次のようになる。

<dl>
  <dt>十字キーの右</dt>
  <dd>ラケットを右へ動かす（等速運動）</dd>
  <dt>十字キーの左</dt>
  <dd>ラケットを左へ動かす（等速運動）</dd>
  <dt><code>R</code>ボタン</dt>
  <dd>ラケットを右へ動かす（等加速度運動）</dd>
  <dt><code>L</code>ボタン</dt>
  <dd>ラケットを左へ動かす（等加速度運動）</dd>
  <dt><code>A</code> + <code>B</code>ボタン</dt>
  <dd>ゲームをリセットする</dd>
</dl>

`START`ボタンのみでゲームを始めた場合、単純なブロック崩しとなる。
ボールが地面に接触したら失敗、全てのブロックを殲滅したらクリアとなる。

`START` + `SELECT`でゲームを始めた場合、ブロックが等速運動をするようになる。
移動するブロックにラケットが接触してもブロックは消滅するが、代償としてラケットの長さが短くなる。
また、ラケットが何回かブロックに接触してラケットの長さが0になると失敗となる。

失敗した場合や成功した場合、`START`ボタンを押すことでリスタート出来る。

--------------
資料で説明した以外の技術
--------------

----------------------------
4分木空間分割
----------------------------

このプログラムは多くの物体との接触判定をしているので、総当たりを行なうとあまりにも時間がかかってしまう。
そこで、空間を16×16への小空間へ分割して、同じ空間に所属する物体をリストにまとめてから接触判定を行っている。

----------------------------
タイマ間隔の変更
----------------------------

講義資料で紹介されているタイマ間隔は1024クロックであったが、これではオーバーフローするまでに4秒もかかってしまう。
これであると、例えば時間`T`で終って欲しいものが`T`で終わらなかった時に、一旦オーバーフローするまでプログラムが停止してしまって、
処理落ち時間が長くなる。
なので、64クロック間隔にして最悪処理落ちしても0.25秒程度で済むようにした。


----------------------------
コールバック関数の登録機能
----------------------------

物体オブジェクトは、

- 他の物体と接触した時
- 移動した時
- 移動に失敗した時

に発火するコールバック関数を登録出来るようにしておいた。
これによって、例えば

- ボールが地面に落ちるとゲームが終了する
- ラケットにブロックが接触するとラケットが縮む

といった処理が容易に追加出来るようになった。

