#pragma once

enum button_states { BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE };

namespace gui
{
	/*##################################################################*/
	/*############################# BUTTON #############################*/
	/*##################################################################*/
	class Button
	{
	protected:
		// #### Variables #### //
		float keyTime;
		float keyTimeMax;

		short unsigned buttonState;
		short unsigned id;

		sf::RectangleShape shape;
		sf::Font* font;
		sf::Text text;

		sf::Color textIdleColor;
		sf::Color textHoverColor;
		sf::Color textActiveColor;

		sf::Color idleColor;
		sf::Color hoverColor;
		sf::Color activeColor;

		sf::Color outlineIdleColor;
		sf::Color outlineHoverColor;
		sf::Color outlineActiveColor;
		// #### Variables #### //
	public:
		// #### Constructor | Destructor #### //
		Button(float x, float y, float width, float height,
			sf::Font* font, std::string text, unsigned characterSize,
			sf::Color textIdleColor, sf::Color textHoverColor, sf::Color textActiveColor,
			sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor,
			sf::Color outlineIdleColor = sf::Color::Transparent,
			sf::Color outlineHoverColor = sf::Color::Transparent,
			sf::Color outlineActiveColor = sf::Color::Transparent,
			short unsigned id = 0);		// Class constructor
		~Button();				// Class destructor
		// #### Constructor | Destructor #### //

		// #### Accessors #### //
		const bool getKeyTime();
		const bool isPressed() const;
		const std::string getText() const;
		const short unsigned& getId() const;
		// #### Accessors #### //

		// #### Modifiers #### //
		void updateKeyTime(const float& dt);
		void setId(const short unsigned id);
		void setText(const std::string text);
		// #### Modifiers #### //

		// #### Functions #### //
		void update(const sf::Vector2f& mousePos, const float& dt);	// Update booleans for hover and pressed
		void render(sf::RenderTarget& target);
		// #### Functions #### //
	};
	/*##################################################################*/
	/*############################# BUTTON #############################*/
	/*##################################################################*/

	/*##################################################################*/
	/*############################# CHECKBOX ###########################*/
	/*##################################################################*/
	class CheckBox
		: public Button
	{
	private:
		// #### Variables #### //
		bool checked;	// If chackbox is checked
		std::string falseStateText;	// Text for false state
		std::string trueStateText;	// Text for true state
		// #### Variables #### //
	public:
		// #### Constructor | Destructor #### //
		CheckBox(float x, float y, float width, float height,
			sf::Font* font, unsigned characterSize,
			sf::Color textIdleColor, sf::Color textHoverColor, sf::Color textActiveColor,
			sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor,
			sf::Color outlineIdleColor = sf::Color::Transparent,
			sf::Color outlineHoverColor = sf::Color::Transparent,
			sf::Color outlineActiveColor = sf::Color::Transparent,
			short unsigned id = 0);		// Class constructor (textStates : {falseStateText, trueStateText})
		~CheckBox();
		// #### Constructor | Destructor #### //

		// #### Modifiers #### //
		void switchState();
		// #### Modifiers #### //

		// #### Accessors #### //
		const bool isChecked() const;
		// #### Accessors #### //

		// #### Functions #### //

		// #### Functions #### //
	};
	/*##################################################################*/
	/*############################# CHECKBOX ###########################*/
	/*##################################################################*/

	/*##################################################################*/
	/*########################### DROPDOWNLIST #########################*/
	/*##################################################################*/
	class DropDownList
	{
	private:
		// #### Variables #### //
		float keyTime;
		float keyTimeMax;

		sf::Font& font;

		gui::Button* activeElement;
		std::vector<gui::Button*> list;
		bool showList;		// Does list shows
		// #### Variables #### //
	public:
		// #### Constructor | Destructor #### //
		DropDownList(float x, float y, float width, float height, sf::Font& font, std::string list[], unsigned nbOfElements, const unsigned defaultIndex = 0);		// Class constructor
		~DropDownList();	// Class destructor
		// #### Constructor | Destructor #### //

		// #### Accessors #### //
		const bool getKeyTime();
		const unsigned short& getActiveElementId() const;
		// #### Accessors #### //

		// #### Functions #### //
		void updateKeyTime(const float& dt);
		void update(const sf::Vector2f& mousePos, const float& dt);	// Update booleans for hover and pressed
		void render(sf::RenderTarget& target);
		// #### Functions #### //
	};
	/*##################################################################*/
	/*########################### DROPDOWNLIST #########################*/
	/*##################################################################*/
}