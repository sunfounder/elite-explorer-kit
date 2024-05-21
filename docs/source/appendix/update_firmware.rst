.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

.. _update_firmware:

UNO R4 WiFiボードのラジオモジュールファームウェアの更新
=====================================================================================

.. https://forum.arduino.cc/t/radio-module-firmware-version-0-2-0-is-now-available/1147361

1. UNO R4 WiFiボードをUSBケーブルでコンピューターに接続します。
2. Arduino IDEのシリアルモニターやシリアルプロッターが実行中の場合は、それらを閉じてください。

   シリアルモニターは、選択時にそのタブに表示されるXアイコンをクリックして閉じることができます：

   .. image:: img/close_serial_monitor2.png
      :width: 85%

3. Arduino IDEのメニューから「Tools」>「Firmware Updater」を選択します。
   「Firmware Updater」ダイアログが開きます。

   .. image:: img/update_firmware_1.png
         :width: 70%

4. 「Firmware Updater」ダイアログの「Select Board」メニューからUNO R4 WiFiを選択します。
5. 「CHECK UPDATES」ボタンをクリックします。
   ダイアログに「INSTALL」ボタンが追加されます。

   .. image:: img/update_firmware_2.png
         :width: 85%

6. 「INSTALL」ボタンをクリックします。
   「Installing firmware」というメッセージがダイアログの下部に表示され、プロセスが開始されます。

   .. image:: img/update_firmware_3.png
         :width: 85%

7. ファームウェアの更新プロセスが成功裏に終了するのを待ちます。ダイアログに次のメッセージが表示されます：
   ファームウェアが正常にインストールされました。

   .. image:: img/update_firmware_4.png
         :width: 85%

8. ダイアログのXアイコンをクリックします。
   ダイアログが閉じます。
9. UNO R4 WiFiボードのUSBケーブルをコンピューターから抜きます。
10. 再度、UNO R4 WiFiボードをUSBケーブルでコンピューターに接続します。


**参考文献**

- |link_update_firmware|
