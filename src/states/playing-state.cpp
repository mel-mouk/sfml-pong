#include "playing-state.h"

void PlayingState::init() {
    Field *field = new Field();
    field->setPosition(100, 200);
    _visibleObjectManager.add("field", field);

    Paddle *player1 = new Paddle(field->getTop() + 10, field->getBottom() - 10);
    _visibleObjectManager.add("player1", player1);

    Paddle *player2 = new Paddle(field->getTop() + 10, field->getBottom() - 10);
    player2->isAI = true;
    _visibleObjectManager.add("player2", player2);

    // Score
    if (!_scoreFont.loadFromFile("../assets/fonts/Roboto-Bold.ttf")) {
        std::cout << "Error while loading Roboto font" << std::endl;
    }
    _scoreText.setFont(_scoreFont);
    _scoreText.setCharacterSize(100);
    _scoreText.setStyle(sf::Text::Bold);
    _scoreText.setFillColor(sf::Color::Black);

    _isDone = false;
    _endGameText.setFont(_scoreFont);
    _endGameText.setCharacterSize(150);
    _endGameText.setStyle(sf::Text::Bold);
    _endGameText.setFillColor(sf::Color::Black);
    
    reset();
}

void PlayingState::reset() {
    // Objects positions
    Paddle *player1 = dynamic_cast<Paddle*>(_visibleObjectManager.get("player1"));
    player1->setPosition(150, 718);
    Paddle *player2 = dynamic_cast<Paddle*>(_visibleObjectManager.get("player2"));
    player2->setPosition(1878, 718);

    // Reset ball
    _visibleObjectManager.remove("ball");
    Field *field = dynamic_cast<Field*>(_visibleObjectManager.get("field"));
    sf::Rect<float> ballConstraint = sf::Rect(field->getLeft() + 10, field->getTop() + 10, field->getBoundingRect().width - 20, field->getBoundingRect().height - 20);
    Ball *ball = new Ball(ballConstraint);
    float centerX = field->getLeft() + field->getBoundingRect().width / 2;
    float centerY = field->getTop() + field->getBoundingRect().height / 2;
    sf::Rect<float> ballRect = ball->getBoundingRect();
    ball->setPosition(centerX - ballRect.width / 2, centerY - ballRect.height / 2);
    _visibleObjectManager.add("ball", ball);

    // Scoring
    _scorePlayer1 = 0;
    _scorePlayer2 = 0;
    _scoreText.setString("0 - 0");
    sf::Rect<float> bound = _scoreText.getGlobalBounds();
    _scoreText.setPosition(Pang::SCREEN_WIDTH / 2 - bound.width / 2, 50);

    // Game status
    _endGameText.setString("");
    _isDone = false;
}

void PlayingState::handleInput(sf::Event *event) {
    if (_isDone) {
        if (event->type == sf::Event::KeyPressed || event->type == sf::Event::MouseButtonPressed) {
            Pang::setState(Pang::Menu);
            reset();
        }
        return;
    }
    _visibleObjectManager.handleInputAll(event);
}

void PlayingState::update(float timeElapsed) {
    if (_isDone) return;
    _visibleObjectManager.updateAll(timeElapsed);
}

void PlayingState::draw(sf::RenderWindow *window) {
    _visibleObjectManager.drawAll(window);
    window->draw(_scoreText);
    if (_isDone) window->draw(_endGameText);
}

void PlayingState::endLoopLogic() {
    if (_isDone) return;
    Ball *ball = dynamic_cast<Ball*>(_visibleObjectManager.get("ball"));

    if (ball->isOut) {
        sf::Vector2<float> ballPosition = ball->getPosition();
        if (ballPosition.x > Pang::SCREEN_WIDTH / 2) {
            _scorePlayer1++;
        } else {
            _scorePlayer2++;
        }
        _scoreText.setString(std::to_string(_scorePlayer1) + " - " + std::to_string(_scorePlayer2));

        _visibleObjectManager.remove("ball");

        if (_scorePlayer1 == 3 || _scorePlayer2 == 3) {
            _isDone = true;
            _endGameText.setString(_scorePlayer1 == 3 ? "Player 1 has won" : "Player 2 has won");
            sf::Rect<float> bound = _endGameText.getGlobalBounds();
            _endGameText.setPosition(Pang::SCREEN_WIDTH / 2 - bound.width / 2, Pang::SCREEN_HEIGHT / 2 - bound.height / 2);
            return;
        }

        Field *field = dynamic_cast<Field*>(_visibleObjectManager.get("field"));
        sf::Rect<float> ballConstraint = sf::Rect(field->getLeft() + 10, field->getTop() + 10, field->getBoundingRect().width - 20, field->getBoundingRect().height - 20);
        Ball *ball = new Ball(ballConstraint);
        float centerX = field->getLeft() + field->getBoundingRect().width / 2;
        float centerY = field->getTop() + field->getBoundingRect().height / 2;
        sf::Rect<float> ballRect = ball->getBoundingRect();
        ball->setPosition(centerX - ballRect.width / 2, centerY - ballRect.height / 2);
        _visibleObjectManager.add("ball", ball);
    }
}