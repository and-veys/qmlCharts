import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtCharts 2.3

Window {
    visible: true
    width: 640
    height: 700
    title: qsTr("Домашняя работа №4")

    ComboBox {
        id: combo
        width:  parent.width
        model: ListModel {}
        onActivated: {
            chart.currentFunction = currentIndex;
            repaint();
        }
        Component.onCompleted: {
            for(let i=0; i<chart.sizeFunctions(); ++i)
                model.append({modelData: chart.getFunctionLabel(i)});
            currentIndex = chart.currentFunction;
        }
    }
    ChartView {
        id:    chart_1
        width: parent.width
        height: 300
        antialiasing: true
        anchors.top: combo.bottom
        title: "Задание №1"
        ValueAxis {
                id: xAxis
                min: 0
                max: 5
                tickInterval: 0.1
        }
        ValueAxis {
                id: yAxis
        }
        LineSeries {
            id: ls
            name: { "Функция: " + chart.getFunctionLabel(chart.currentFunction) }
            axisX: xAxis;
            axisY: yAxis;
        }
        Component.onCompleted: repaint()
    }
    ChartView {
        width: parent.width
        height: 300
        antialiasing: true
        anchors.top: chart_1.bottom
        title: "Задание №2"
        ValueAxis {
                id: xAxis2
        }
        ValueAxis {
                id: yAxis2
        }
        ScatterSeries {
            id: sc_data
            name: "Данные точки"
            axisX: xAxis2;
            axisY: yAxis2;

        }
        LineSeries {
            id: sc_line
            name: "Линейная зависимость"

        }
        Component.onCompleted: linefunction()


    }
    function repaint() {
        ls.clear();
        let min = Infinity;
        let max = -Infinity;
        let k;
        for(let i=xAxis.min; i<xAxis.max; i+=xAxis.tickInterval) {
            k = chart.calculate(i);
            if(k === -Infinity || k === Infinity)
                continue;
            max = Math.max(max, k);
            min = Math.min(min, k);
            ls.append(i, k);
        }
        setAxis(yAxis, min, max);
    }
    function linefunction() {
        let sz = line.getSize();
        let ptD;
        let ptL
        let minX = Infinity;
        let maxX = -Infinity;
        let minY = Infinity;
        let maxY = -Infinity;
        for(let i=0; i<sz; ++i) {
            ptD = line.getPointData(i);
            ptL = line.getPointLine(i);
            sc_data.append(ptD.x, ptD.y);
            sc_line.append(ptL.x, ptL.y);
            minX = Math.min(minX, ptD.x, ptL.x);
            maxX = Math.max(maxX, ptD.x, ptL.x);
            minY = Math.min(minY, ptD.y, ptL.y);
            maxY = Math.max(maxY, ptD.y, ptL.y);
        }
        setAxis(xAxis2, minX, maxX);
        setAxis(yAxis2, minY, maxY);
    }
    function setAxis(ax, min, max) {
        let k = (max-min)*0.1;
        ax.min = min - k;
        ax.max = max + k;
    }
}
