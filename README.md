# MovieHighlighter
<html>
  <body>
    <article>
      <p>
        Приложение для записи игровых хайлайтов, написанное на С++ при помощи фреймворка Qt, библиотеки OpenCV и ffmpeg на MVC архитектуре. Оно читает видеофайл 
        с геймплеем какой-либо игры и ищет отрывки с убийствами игроков при помощи компьютерного зрения. Нахождение убийств осуществляется за счет обнаружения 
        шаблонного изображения, которое свидетельствует об этом самом моменте
      </p>
      <br>
      <br>
    </article>
    <nav>
      <h2>Панель навигации</h2>
      <ul>
        <li><a href="#1">Как собрать или установить</a></li>
        <li><a href="#2">Подробнее о реализации</a></li>
        <li><a href="#3">Как использовать</a></li>
      </ul>
    </nav>
    <br>
    <br>
    <article>
      <h2 id="1">Как собрать или установить</h2>
      <p>
        Для сборки проекта из исходников необходимо воспользоваться CMake, но перед этим нужно подготовить среду: 
        библиотеки OpenCV и Qt должны быть привязаны к системной переменной среды Path. После сборки нам нужно закинуть <a href="https://ffmpeg.org/download.html">ffmpeg</a> 
        в корневую папку с исполняемым файлом, нас интересует ffmpeg.exe и все динаические библиотеки dll, которые там будут (папка bin)
      </p>
      <p>
        Во избежании нежелательного стресса, есть уже собранное приложение под <a href="https://github.com/Alexxxium/Builds/tree/main/MovieHighlighter">Windows</a>
      </p>
      <br>
      <br>
    </article>
    <article>
      <br>
      <h2 id="2">Подробнее о реализации</h2>
      <h3>Захват интересующего кадра</h3>
      <p>
        В ядро приложения поступает множество параметров, ключевым из которых является изображение, характеризующее убийство: ваш ник в килчате, вспышка, надпись и т.п. 
        На него, как и на читаемые кадры, накладывается маска, которая ищет и выделяет контуры - теперь изображение и считанный кадр имеют одинаковый цветовой спектор и уже проще распознать шаблон. 
        Пользователь может оптимизировать этот подход, явно указав область сканирования - чем меньше область и сам шаблон, тем быстрее и лучше осущетвляется поиск
      </p>
      <br>
      <h3>Чтение и вложенная многопоточность</h3>
      <p>
        Видео с игрой разбивается на несколько частей, каждую из которых обрабатывает отдельный поток.
        Суть быстрого чтения, заглючается в считывании каждого n-ного кадра, где n не превышает длительности флага с убийством. Наткнувшись на нужный кадр, 
        переллельно запускается бинарный поиск начала и конца хайлайта (моя собственная <a href="https://github.com/Alexxxium/Algorithms/tree/master/WaiteQueue">потоковая очередь</a>). 
        После завершения всех потоков, полученные отрезки корректируются по параметрам пользователя: 
        добавляется время до и после хайлайта, а так же склеиваются серии убийств. За запись отвечает сам ffmpeg, которому передается текстовый файл со всеми временными отрезками.
      </p>
      <br>
      <br>
    </article>
    <article>
      <h2 id="3">Как использовать</h2>
      <p>
        Интерфейс сделан в Singlepage стиле. В левой его части расположены основные настройки для параметров поиска, а сверху пути к видео:
      </p>
      <br>
      <figure>
        <contitle><h3>Interface</h3></contitle>
        <img src="https://github.com/Alexxxium/DocumentationSources/blob/main/MovieHighlighter/frontView.png", alt="Image go for a walk">
        <h2></h2>
      </figure>
      <br>
      <br>
      <p>
        Т.к. игры разные, как и флаги убийств, то вы можете создавать/редактировать свои настройки под каждую игру
        + учтена попытка намеренного удаления файлов настроек:
      </p>
      <br>
      <figure>
        <contitle><h3>New settings</h3></contitle>
        <img src="https://github.com/Alexxxium/DocumentationSources/blob/main/MovieHighlighter/newFrontView.png", alt="Image go for a walk">
      </figure>
      <h2></h2>
      <br>
      <br>
      <p>
        Некорректный ввод спокойно обработается, т.к. приложению заранее станет известно о метриках видео и о других его свойств:
      </p>
      <br>
      <figure>
        <contitul><h3>Error</h3></contitul>
        <img src="https://github.com/Alexxxium/DocumentationSources/blob/main/MovieHighlighter/errorView.png", alt="Image go for a walk">
      </figure>
      <h2></h2>
      <br>
      <br>
      <p>
        Вы можете посмотреть процесс сканирования в реальном времени:
      </p>
      <br>
      <figure>
        <contitle><h3>Run time</h3></contitle>
        <img src="https://github.com/Alexxxium/DocumentationSources/blob/main/MovieHighlighter/realTimeView.png", alt="Image go for a walk">
      </figure>
      <h2></h2>
      <br>
      <br>
      <p>
        Или читать логи:
      </p>
      <br>
      <figure>
        <contitle><h3>Logs</h3></contitle>
        <img src="https://github.com/Alexxxium/DocumentationSources/blob/main/MovieHighlighter/proccessView.png", alt="Image go for a walk">
      </figure>
    </article>
  </body>
</html>