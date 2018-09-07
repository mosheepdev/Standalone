local item = Item("Criticalis")

------------------------------------------------------------------------------------------------------------------------
function item:GetBonusDamage()
    return self:GetValue("Bonus_Damage")
end

------------------------------------------------------------------------------------------------------------------------
function item:GetCriticalChance()
    return self:GetValue("Critical_Chance")
end

function item:GetCriticalPercentage()
    return self:GetValue("Critical_Percentage")
end
