async function loadData() {
  const response = await fetch('sensor_data.json');
  const data = await response.json();

  const container = document.getElementById('container');
  container.innerHTML = '';

  for (let sector in data) {
    const aqi = data[sector].aqi;
    const led = aqi > 150 ? "ON" : "OFF";

    container.innerHTML += `
      <div style="margin-bottom: 20px; border: 1px solid black; padding: 10px;">
        <h3>${sector}</h3>
        <p>AQI: ${aqi}</p>
        <p>LED Status: <strong>${led}</strong></p>
      </div>
    `;
  }
}

loadData();
