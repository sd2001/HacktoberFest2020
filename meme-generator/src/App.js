import React from 'react';
import Header from './MemeGeneratore';
import MemeGenerator from './Header';
import { Stage, Layer, Rect, Image } from 'react-konva';
import Konva from 'konva';
import './App.css';
import { Typography, Row, Col } from 'antd';

const { Title } = Typography;

// class ColoredRect extends React.Component {
//   state = {
//     color: 'green',
//   };
//   handleClick = () => {
//     this.setState({

//     });
//   };
//   render() {
//     return (
//       <Stage width={window.innerWidth} height={window.innerHeight}>
//         <Layer style={{ display: 'flex', justifyContent: 'center' }}>
//           <Rect
//             x={20}
//             y={20}
//             width={1000}
//             height={1000}
//             fill={this.state.color}
//             shadowBlur={5}
//             onClick={this.handleClick}
//           />
//         </Layer>
//       </Stage>
//     );
//   }
// }
class URLImage extends React.Component {
  state = {
    image: null,
  };
  componentDidMount() {
    this.loadImage();
  }
  componentDidUpdate(oldProps) {
    if (oldProps.src !== this.props.src) {
      this.loadImage();
    }
  }
  componentWillUnmount() {
    this.image.removeEventListener('load', this.handleLoad);
  }
  loadImage() {
    this.image = new window.Image();
    this.image.src = this.props.src;
    this.image.addEventListener('load', this.handleLoad);
  }
  handleLoad = () => {
   
    this.setState({
      image: this.image,
    });
  };
  render() {
    return (
      <Image
        x={this.props.x}
        y={this.props.y}
        image={this.state.image}
        ref={(node) => {
          this.imageNode = node;
        }}
      />
    );
  }
}

function App() {
  const handleClick = () => {
    this.setState({
      color: Konva.Util.getRandomColor(),
    });
  };

  return (
    <div>
      {/* <Row style={{}}>
        <Col span={24} style={{ display: 'flex', justifyContent: 'center' }}>
          <Title level={1}>
            Meme generator
          </Title>
        </Col>
        <Col span={24} style={{ display: 'flex', justifyContent: 'center' }}>
          <Stage width={window.innerWidth} height={window.innerHeight}>
            <Layer>
              <URLImage src="https://konvajs.org/assets/yoda.jpg" x={150} />
            </Layer>
          </Stage>
          <ColoredRect/>
        </Col>
      </Row> */}
      <Header />
      <MemeGenerator />
    </div>
  );
}

export default App;
