item_crystalys = base(Item)

------------------------------------------------------------------------------------------------------------------------

function item_crystalys:GetBonusDamage()
    return self:GetValue("bonus_damage")
end

------------------------------------------------------------------------------------------------------------------------

function item_crystalys:GetCriticalChance()
    return self:GetValue("critical_chance")
end

function item_crystalys:GetCriticalPercentage()
    return self:GetValue("critical_percentage")
end
