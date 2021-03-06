/*
 * Copyright (c) 2015 WinT 3794 <http://wint3794.org>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef _QDS_ADVANCED_SETTINGS_H
#define _QDS_ADVANCED_SETTINGS_H

#include <QList>
#include <QDialog>
#include <ui_AdvancedSettings.h>

/**
 * @class AdvancedSettings
 * @brief Implements a dialog for users that seek to customize the application
 *
 * The \c AdvancedSettings dialog allows the user to change the network settings
 * of the DriverStation and to change the palette of the application
 * (ex: to match the colors of the user's team)
 */
class AdvancedSettings : public QDialog
{
    Q_OBJECT

public:
    /**
     * @internal
     * Configures the user interface and the dialog and loads the saved
     * settings in the UI controls
     */
    explicit AdvancedSettings();

    /**
     * This enum represents the different colors that compose the palette
     * of the application. The colors in this structure will be adapted
     * automatically by the application to change the look of the widgets
     */
    enum Colors {
        Base,       /**< Used for the base color of the window */
        Highlight,  /**< Used for highlighted elements */
        Background, /**< Used to fill the background of most widgets */
        Foreground  /**< Used for labels and other 'text' objects */
    };

    /**
     * Updates the placeholder text of the custom address to match current
     * team number
     */
    void setTeamNumber (int team);

signals:
    void settingsChanged();

private:
    Ui::AdvancedSettings ui;
    QList<QLabel*> m_colorBoxes;
    QList<QLineEdit*> m_colorTexts;

private slots:
    /**
     * @internal
     * Reads settings and updates dialog UI accordingly
     */
    void readSettings();

    /**
     * @internal
     * Changes settings based on the values of the UI elements
     */
    void applySettings();

    /**
     * @internal
     * Resets all the settings that are managed by this dialog to their default
     * values
     */
    void resetSettings();

    /**
     * @internal
     * Changes the palette of the application based on current settings
     */
    void loadApplicationColors();

    /**
     * @internal
     * Clears the settings and re-loads them
     */
    void onResetClicked();

    /**
     * @internal
     * Applies the settings, updates the UI and closes the dialog
     */
    void onApplyClicked();

    /**
     * @internal
     * Resets the UI elements to match previous settings and closes the dialog
     */
    void onCancelClicked();

    /**
     * @internal
     * Shows a color dialog that allows the user to change a color of the UI
     */
    void onSelectorClicked();

    /**
     * @internal
     * Changes the color of the color box assigned to the line edit
     * that emited the signal that called this function
     */
    void onColorChanged (QString color);

    /**
     * @internal
     * Returns the current color on the line edit that matches the \a type
     */
    QColor getColor (int type);

    /**
     * @internal
     * Returns the emitter of a signal based on its object name
     */
    int getEmitter (const QObject* object);
};

#endif /* _QDS_ADVANCED_SETTINGS_H */
