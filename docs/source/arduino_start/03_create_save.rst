.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

スケッチの作成、開く、保存方法
=======================================

1. Arduino IDEを初めて開く場合や新しいスケッチを作成する場合、このようなページが表示されます。ここでArduino IDEは新しいファイルを作成し、それを「スケッチ」と呼びます。

   .. image:: img/sp221014_173458.png

   これらのスケッチファイルには一般的な一時的な名前が付けられており、ファイル作成日を知ることができます。 ``sketch_oct14a.ino`` は10月14日の最初のスケッチを意味し、 ``.ino`` はこのスケッチのファイル形式です。

2. 新しいスケッチを作成してみましょう。次のコードをArduino IDEにコピーして、元のコードを置き換えてください。

   .. image:: img/create1.png

   .. code-block:: Arduino

       void setup() {
           // put your setup code here, to run once:
           pinMode(13,OUTPUT); 
       }

       void loop() {
           // put your main code here, to run repeatedly:
           digitalWrite(13,HIGH);
           delay(500);
           digitalWrite(13,LOW);
           delay(500);
       }

3. ``Ctrl+S`` を押すか、 **File** -> **Save** をクリックします。スケッチはデフォルトで ``C:\Users\{ユーザー名}\Documents\Arduino`` に保存されますが、名前を変更するか、新しいパスを見つけて保存することができます。

   .. image:: img/create2.png

4. 保存に成功すると、Arduino IDEの名前が更新されたことが分かります。

   .. image:: img/create3.png

次のセクションで、作成したこのスケッチをArduinoボードにアップロードする方法を学びましょう。
